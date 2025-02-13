/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleLocal";

_this params [
	["_vehicle", objNull, [objNull]],
	["_isLocal", false, [true]]
];

if (isServer && { _isLocal } && { isEngineOn _vehicle }) then {
	_vehicle engineOn false;
};

if (isNull (driver _vehicle) && { !(isNull (_vehicle getVariable ["siren", objNull])) }) then {
	[_vehicle, [], false] call ULP_fnc_vehicleSiren;
};