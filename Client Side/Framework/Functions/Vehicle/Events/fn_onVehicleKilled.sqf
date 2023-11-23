/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleKilled";

_this params [
	["_vehicle", objNull, [objNull]],
	["_killer", objNull, [objNull]],
	["_instigator", objNull, [objNull]]
];

if (local _vehicle) then {
	[_vehicle, [], false] call ULP_fnc_vehicleSiren;
};