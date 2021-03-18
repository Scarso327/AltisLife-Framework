/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isVehicleOwner";

_this params [
	["_unit", player, [objNull]],
	["_vehicle", objNull, [objNull]]
];

!(isNull _vehicle) && { alive _vehicle } && { ([_vehicle] call ULP_fnc_getVehicleOwner) isEqualTo (getPlayerUID _unit) }