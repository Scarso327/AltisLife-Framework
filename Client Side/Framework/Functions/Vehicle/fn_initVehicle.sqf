/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initVehicle";

if (canSuspend) exitWith {
	_this call ULP_fnc_initVehicle;
};

_this params [
	["_vehicle", objNull, [objNull]],
	["_jip", false, [true]]
];

if (isNull _vehicle || { _vehicle getVariable ["ready", false] }) exitWith {};
_vehicle setVariable ["ready", true];

if (local _vehicle) then {
	if (_jip) exitWith {};

	_vehicle setAmmoCargo 0;
	_vehicle setFuelCargo 0;
	_vehicle setRepairCargo 0;

	clearWeaponCargoGlobal _vehicle;
	clearMagazineCargoGlobal _vehicle;
	clearItemCargoGlobal _vehicle;
	clearBackpackCargoGlobal _vehicle;

	[_vehicle] remoteExecCall ["ULP_fnc_initVehicle", -clientOwner];

	_vehicle setVariable["jipReady", true, true];
};

