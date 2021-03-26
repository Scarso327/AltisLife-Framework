/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_lock";

_this params [
	["_vehicle", objNull, [objNull]],
	["_lock", 0, [0]]
];

if !(isClass (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle))) exitWith { false };

_vehicle lock _lock;
true