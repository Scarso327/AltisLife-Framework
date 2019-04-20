/*
    File: fn_gather.sqf
    Author: Devilfloh

    Description:
    Main functionality for gathering.
*/
#include "..\..\script_macros.hpp"

if (life_action_inUse) exitWith {};
if !(isNull objectParent player) exitWith {};
if (player getVariable "restrained") exitWith {hint "You cannot do this while you are restrained.";};
if (player getVariable "playerSurrender") exitWith {hint "You cannot do this while you are surrendered.";};

life_action_inUse = true;
_zone = "";
private _resource = "";
private _requiredItem = "";
private _maxGather = 1;
private _upp = "Gathering Something";
_exit = false;

// Professions...
private _profession = [];
private _profZone = "";
private _profXP = 0;
private _profChance = 0;

_resourceCfg = missionConfigFile >> "CfgGather" >> "Resources";
for "_i" from 0 to count(_resourceCfg)-1 do {

    _curConfig = _resourceCfg select _i;
    _resource = configName _curConfig;
    _maxGather = getNumber(_curConfig >> "amount");
    _zoneSize = getNumber(_curConfig >> "zoneSize");
    _resourceZones = getArray(_curConfig >> "zones");
    _requiredItem = getText(_curConfig >> "item");
    _profession = getArray(_curConfig >> "profession");
    _upp = getText(_curConfig >> "text");
    {
        if ((player distance (getMarkerPos _x)) < _zoneSize) exitWith {_zone = _x;};
    } forEach _resourceZones;

    if (_zone != "") exitWith {};
};

if (_zone isEqualTo "") exitWith {life_action_inUse = false;};

_profZone = _profession select 0;
_profXP = _profession select 1;
_profChance = _profession select 2;

if (_requiredItem != "") then {
    _valItem = missionNamespace getVariable "life_inv_" + _requiredItem;

    if (_valItem < 1) exitWith {
        switch (_requiredItem) do {
         //Messages here
        };
        life_action_inUse = false;
        _exit = true;
    };
};

if (_exit) exitWith {life_action_inUse = false;};

private _amount = round(random(_maxGather)) + 1;
_diff = [_resource,_amount,life_carryWeight,life_maxWeight] call life_fnc_calWeightDiff;
if (_diff isEqualTo 0) exitWith {
    hint "Your inventory space is full.";
    life_action_inUse = false;
};

switch (_requiredItem) do {
    case "pickaxe": {[player,"mining",35,1] remoteExecCall ["life_fnc_say3D",RCLIENT]};
    default {[player,"harvest",35,1] remoteExecCall ["life_fnc_say3D",RCLIENT]};
};

// Progress Bar!
disableSerialization;
"progressBar" cutRsc ["life_progress","PLAIN"];
private _ui = uiNamespace getVariable "life_progress";
private _progress = _ui displayCtrl 38201;
private _pgText = _ui displayCtrl 38202;
_pgText ctrlSetText format ["%2 (1%1)...","%",_upp];
_progress progressSetPosition 0.01;
private _cP = 0.01;

for "_i" from 0 to 1 step 0 do {
    player playMoveNow "AinvPercMstpSnonWnonDnon_Putdown_AmovPercMstpSnonWnonDnon";
    waitUntil{animationState player != "AinvPercMstpSnonWnonDnon_Putdown_AmovPercMstpSnonWnonDnon";};

    uiSleep 0.5;

    _cP = _cP + 0.01;
    _progress progressSetPosition _cP;
    _pgText ctrlSetText format ["%3 (%1%2)...",round(_cP * 100),"%",_upp];
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

if ([true,_resource,_diff] call life_fnc_handleInv) then {
    _itemName = M_CONFIG(getText,"CfgItems",_resource,"displayName");

    [_profZone,_profXP,_profChance] call FF_fnc_increaseProfession;

    titleText[format ["You have gathered %2 %1(s).",(localize _itemName),_diff],"PLAIN"];
};

sleep 1;
life_action_inUse = false;