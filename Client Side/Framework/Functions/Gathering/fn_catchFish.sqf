/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_catchFish";

_this params [
	["_fish", objNull, [objNull]]
];

if (isNull _fish || { alive _fish }) exitWith { false };

private _typeOf = typeOf _fish;

if !(_typeOf in getArray (missionConfigFile >> "CfgGathering" >> "fish")) exitWith { false };

// Check turtle zoning...
if (_typeOf isEqualTo "Turtle_F") then {
	private _zones = getArray (missionConfigFile >> "CfgGathering" >> "turtleZones");

	if ((_zones findIf { (player distance (getMarkerPos _x)) <= 250 }) < 0) then {
		["You must be within a turtle poaching zone to catch turtles!"] call ULP_fnc_hint;
		false breakOut "fn_catchFish";
	};
};

private _name = (_typeOf splitString "_") param [0, "Fish"];

if ([format["%1_Raw", _typeOf], 1] call ULP_fnc_handleItem) exitWith {
	deleteVehicle _fish;
	
	[format ["You've picked up a <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;

	["Fishing", 1, 40] call ULP_fnc_increaseProfession;

	true
};

[format ["You don't have enough inventory space to hold <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;