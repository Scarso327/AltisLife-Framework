/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleDeleted";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (local _vehicle) then {
	[_vehicle, [], false] call ULP_fnc_vehicleSiren;
};