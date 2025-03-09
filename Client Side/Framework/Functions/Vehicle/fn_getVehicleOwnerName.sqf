/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getVehicleOwnerName";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];
if (_owner isEqualTo []) exitWith { "Unknown" };

(_owner param [0, "Unknown"])