/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isVehicleStationary";

_this params [
	["_vehicle", objNull, [objNull]],
	["_initialPosition", getPos _vehicle, [[]]]
];

!(isEngineOn _vehicle && { (_vehicle distance _initialPosition) > 10 })