/*
	@File: fn_gatherItem.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Handles gather zones...
*/
scopeName "Gathering";
#include "..\..\script_macros.hpp"
#define CFG missionConfigFile >> "CfgGathering"

// Initial Checks...
if (life_action_inUse) exitWith {};
if !(isNull objectParent player) exitWith {};
if (player getVariable ["restrained", false]) exitWith { hint "You cannot do this while you are restrained." };
if (player getVariable ["playerSurrender", false]) exitWith { hint "You cannot do this while you are surrendered." };

life_action_inUse = true;

// Initial Variable Definition...
private _zone = "";
private _gConfigs = CFG;

// Get the zone we're currenlty in...
for "_i" from 0 to (count(_gConfigs) - 1) do {
	private _curConfig = _gConfigs select _i;
	private _zoneSize = getNumber(_curConfig >> "zoneSize");

	{
		if ((player distance(getMarkerPos _x)) < _zoneSize) exitWith {
            _zone = (configName _curConfig);
        };
	} forEach (getArray(_curConfig >> "zones"));
};

if (_zone isEqualTo "") exitWith { life_action_inUse = false }; // Ensure we've got a zone...

// Zone Variable Definition...
private _myZone = CFG >> _zone;
private _chance = (floor random 100) + 1;
private _gatherItem = getText(_myZone >> "gathered");
private _maxGather = getNumber(_myZone >> "amount");
private _requiredItem = getText(_myZone >> "item");

// Check if we have the required item...
if !(_requiredItem isEqualTo "") then {
	if !(ITEM_VALUE(_requiredItem) > 0) then {
		private _itemName = M_CONFIG(getText,"CfgItems",_requiredItem,"displayName");

		titleText[format["This zone requires the use of a %1.", _itemName], "PLAIN"];
		
		life_action_inUse = false;
		breakOut "Gathering";
	};
};

// More Variable Definition...
private _title = getText(_myZone >> "text");
private _amount = round(random(_maxGather)) + 1;
private _profession = getArray(_myZone >> "profession");

// Split the profession array...
private _profZone = _profession select 0;
private _profRequirement = _profession select 1;
private _profXP = _profession select 2;
private _profChance = _profession select 3;

if (PROF_LVL(_profZone) < _profRequirement) exitWith { hint "You don't meet the profession requirement for this zone..." };

// Check if we can fit the items...
private _diff = [_gatherItem, _amount, life_carryWeight, life_maxWeight] call LIFE(calWeightDiff);
if (_diff isEqualTo 0) exitWith {
    hint "Your inventory space is full.";
    life_action_inUse = false;
};

// Progress Bar!
disableSerialization;
"progressBar" cutRsc ["life_progress","PLAIN"];
private _ui = uiNamespace getVariable "life_progress";
private _progress = _ui displayCtrl 38201;
private _pgText = _ui displayCtrl 38202;
_pgText ctrlSetText format ["%2 (1%1)...","%", _title];
_progress progressSetPosition 0.01;
private _cP = 0.01;

for "_i" from 0 to 1 step 0 do {
    player playMoveNow "AinvPercMstpSnonWnonDnon_Putdown_AmovPercMstpSnonWnonDnon";
    waitUntil{animationState player != "AinvPercMstpSnonWnonDnon_Putdown_AmovPercMstpSnonWnonDnon";};

    uiSleep 0.5;

    _cP = _cP + 0.01;
    _progress progressSetPosition _cP;
    _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%", _title];
    if (_cP >= 1) exitWith {};
    if (!(alive player) || isDowned(player)) exitWith {};
    if !(isNull objectParent player) exitWith {};
    if (life_interrupted) exitWith {};
};

"progressBar" cutText ["","PLAIN"];
player playActionNow "stop";
if (!(alive player) || isDowned(player)) exitWith {};
if (life_interrupted) exitWith {life_interrupted = false; titleText["Action Cancelled.","PLAIN"]; life_action_inUse = false;};
if !(isNull objectParent player) exitWith {titleText["You cannot do this while you are in a vehicle.","PLAIN"]; life_action_inUse = false;};

if ([true,_gatherItem,_diff] call life_fnc_handleInv) then {
    private _itemName = M_CONFIG(getText,"CfgItems",_gatherItem,"displayName");

    [_profZone,_profXP,_profChance] call FF(increaseProfession);

    titleText[format ["You have gathered %2 %1(s).",_itemName,_diff],"PLAIN"];
};

sleep 1;
life_action_inUse = false;