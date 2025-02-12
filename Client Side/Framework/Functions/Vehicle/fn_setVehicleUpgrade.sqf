/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setVehicleUpgrade";

_this params [
	["_vehicle", objNull, [objNull]],
	["_upgrade", "", [""]]
];

private _cfg = missionConfigFile >> "CfgVehicleUpgrades" >> _upgrade;
if (isNull _vehicle || { !isClass _cfg }) exitWith { false };

private _upgrades = + (_vehicle getVariable ["vehicle_upgrades", createHashMap]);
_upgrades set [_upgrade, true];

_vehicle setVariable ["vehicle_upgrades", _upgrades, true];

[_vehicle] remoteExecCall ["ULP_SRV_fnc_saveVehicleUpgrades", RSERV];

_vehicle call compile getText (_cfg >> "onApplied");

true