/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleCfg";

_this params [
	["_vehicle", "", [""]]
];

private _armaCfg = configFile >> "CfgVehicles" >> _vehicle;
if !(isClass _armaCfg) exitWith { [] };

private _missionCfg = missionConfigFile >> "CfgVehicles" >> _vehicle;

[
  _armaCfg,
  _missionCfg,
  getText(_armaCfg >> "picture"),
  getText(_armaCfg >> "displayName"),
  getNumber(_armaCfg >> "maxSpeed"),
  getNumber(_armaCfg >> "armor"),
  getNumber(_armaCfg >> "transportSoldier"),
  getNumber(_armaCfg >> "enginePower"),
  getNumber(_armaCfg >> "fuelCapacity")
]