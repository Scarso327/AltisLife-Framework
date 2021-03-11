/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_initVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_vehicle", objNull, [objNull]],
	["_jip", false, [true]]
];

if (isNull _vehicle || { _vehicle getVariable ["ready", false] }) exitWith {};
_vehicle setVariable ["ready", true];

if (local _vehicle) then {
	if (_jip) exitWith {};

	[_vehicle] call ULP_fnc_setVehicleAmmo;

	[_vehicle] remoteExecCall ["ULP_fnc_initVehicle", -clientOwner];

	_vehicle setVariable["jipReady", true, true];
};

_vehicle addEventHandler ["Killed", { _this call ULP_fnc_onVehicleKilled }];
_vehicle addEventHandler ["Deleted", { _this call ULP_fnc_onVehicleDeleted }];