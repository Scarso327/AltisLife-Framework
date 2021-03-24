/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_ejectVehicleUnit";

_this params [
	["_unit", objNull, [objNull]]
];

private _vehicle = vehicle _unit;

if (_unit isEqualTo _vehicle) exitWith { false };

unassignVehicle _unit;
moveOut _unit;
true