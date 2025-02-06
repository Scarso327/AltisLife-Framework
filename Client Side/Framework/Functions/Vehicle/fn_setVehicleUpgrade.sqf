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

if (isNull _vehicle || { !isClass (missionConfigFile >> "CfgVehicleUpgrades" >> _upgrade) }) exitWith { false };

private _upgrades = + (_vehicle getVariable ["vehicle_upgrades", createHashMap]);
_upgrades set [_upgrade, true];

_vehicle setVariable ["vehicle_upgrades", _upgrades, true];

[_vehicle] remoteExecCall ["ULP_SRV_fnc_saveVehicleUpgrades", RSERV];

true