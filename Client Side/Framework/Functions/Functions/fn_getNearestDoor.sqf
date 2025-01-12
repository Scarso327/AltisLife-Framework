/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getNearestDoor";

_this params [
	["_building", objNull, [objNull]],
	["_unit", player, [objNull]]
];

private _doors = [_building] call ULP_fnc_getBuildingDoors;

if (_doors isEqualTo []) exitWith { -1 };

_doors = (_doors apply { _unit distance _x });

private _nearestDoor = (_doors findIf { _x <= 2.5 });

if (_nearestDoor isEqualTo -1) exitWith { -1 };

_nearestDoor + 1