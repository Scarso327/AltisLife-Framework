/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_dropFishingNet";

private _vehicle = vehicle player;

if (_vehicle isEqualTo player || { !(_vehicle isKindOf "Ship") } || { (speed _vehicle) > 2 || { (speed _vehicle) < -2  } }) exitWith {
	["You must be in a boat and stationary!"] call ULP_fnc_hint;
	false
};

private _terrainHeight = getTerrainHeightASL (getPos _vehicle);

if (_terrainHeight > -40) exitWith {
	["The water isn't deep enough here"] call ULP_fnc_hint;
	false
};

if !(["FishingNet", 1, true] call ULP_fnc_handleItem) exitWith {
	["You must have a fishing net to drop first"] call ULP_fnc_hint;
	false
};

private _zone = missionConfigFile >> "CfgGathering" >> "Fishing";
if !(isClass (_zone >> "Nets")) exitWith {};

private _time = getNumber(_zone >> "Nets" >> "time");

if !(_profession isEqualTo []) then {
	private _profCal = ["Fishing"] call ULP_fnc_getProfessionCalculation;
	if (_profCal > 0) then { _time = _time - (_time * (_profCal / 100)); };
};


["Waiting For Fish...", _time, [_zone], {
	!isNull (objectParent player) && { (speed (vehicle player)) <= 3 } && { (speed (vehicle player)) >= -3  }
}, {
	private _zone = _this param [0, configNull, [configNull]];

	["FishingNet", 1, false, true] call ULP_fnc_handleItem;

	private _chance = random 1;
	
	if !(getNumber (_zone >> "Nets" >> "chance") > random 1) exitWith {
		["You didn't catch any fish"] call ULP_fnc_hint;
	};

	private _fish = selectRandom (getArray (_zone >> "fish") select {
		!(_x isEqualTo "Turtle_F")
	});

	private _item = missionConfigFile >> "CfgVirtualItems" >> format["%1_Raw", _fish];
	if !(isClass _item) exitWith {};

	private _maxQuantity = [getNumber(_item >> "weight")] call ULP_fnc_getMaxQuantity;

	private _amount = (round (random (getArray (_zone >> "Nets" >> "randomAmount")))) min _maxQuantity;

	if (_amount isEqualTo 0) exitWith {
		["You caught some fish but had no room in your inventory so had to let them go"] call ULP_fnc_hint;
	};

	[configName _item, _amount, false, true] call ULP_fnc_handleItem;

	[format["You've caught <t color='#B92DE0'>%1 %2(s)</t>.", _amount, getText(_item >> "displayName")]] call ULP_fnc_hint;
	["GatheredVirtualItem", [configName _item, _amount]] call ULP_fnc_invokeEvent;

	private _profession = getArray (_zone >> "Nets" >> "profession");
	private _leveling = getArray (_zone >> "Nets" >> "leveling");

	if (time >= (player getVariable ["GatherCooldown", time - 30])) then {
		if !(_profession isEqualTo []) then { _profession call ULP_fnc_increaseProfession; };
		if !(_leveling isEqualTo []) then { _leveling call ULP_fnc_addXP; };
		player setVariable ["GatherCooldown", time + 30];
	};
}, {
	["You must remain in your boat and keep it still"] call ULP_fnc_hint;
	["FishingNet", 1, false, true] call ULP_fnc_handleItem;
}] call ULP_UI_fnc_startProgress;