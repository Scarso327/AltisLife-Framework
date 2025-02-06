/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasVehicleUpgrade";

_this params [
	["_vehicle", objNull, [objNull]],
	["_upgrade", "", [""]]
];

if (isNull _vehicle || { !isClass (missionConfigFile >> "CfgVehicleUpgrades" >> _upgrade) }) exitWith { false };

(_upgrade in (_vehicle getVariable ["vehicle_upgrades", createHashMap]))