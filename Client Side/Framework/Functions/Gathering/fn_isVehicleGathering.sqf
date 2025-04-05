/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isVehicleGathering";

_this params [
	["_vehicle", objNull, [objNull]]
];

(!isNull (_vehicle getVariable ["mining", objNull]) && { _vehicle getVariable ["locked", true] })