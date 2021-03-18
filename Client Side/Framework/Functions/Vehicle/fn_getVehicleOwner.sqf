/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getVehicleOwner";

_this params [
	["_vehicle", objNull, [objNull]]
];

((keys (_vehicle getVariable ["vehicle_owners", createHashMap])) param [0, ""])