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

private _doors = (([_building] call ULP_fnc_getBuildingDoors) apply {
	_unit distance _x
});

(_doors findIf { _x <= 2.5 }) + 1