/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setFuel";

_this params [
	["_vehicle", objNull, [objNull]],
	["_fuel", 0, [0]]
];

if !(isClass (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle))) exitWith { false };
if !(local _vehicle) exitWith { _this remoteExecCall ["ULP_fnc_setFuel", _vehicle]; true };

_vehicle setFuel _fuel;
true