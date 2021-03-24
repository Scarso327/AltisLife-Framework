/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_ejectVehicleCrew";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle || { (speed _vehicle) > 5 } ) exitWith { false };

({ [_x] call ULP_fnc_ejectVehicleUnit } count (crew _vehicle) > 0)