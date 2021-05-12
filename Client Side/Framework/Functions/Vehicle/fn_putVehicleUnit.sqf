/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_putVehicleUnit";

_this params [
	["_vehicle", objNull, [objNull]],
	["_unit", objNull, [objNull]]
];

if (isNull _vehicle || { isNull _unit } || { (vehicle _unit) isEqualTo _vehicle }) exitWith { false };

_unit moveInCargo _vehicle;
true