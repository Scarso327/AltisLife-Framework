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

private _parentCfgs = [_armaCfg, true] call BIS_fnc_returnParents;
private _missionCfg = if ("House" in _parentCfgs) then {
    missionConfigFile >> "CfgHousing" >> "Houses" >> _vehicle;
} else {
    missionConfigFile >> "CfgVehicles" >> _vehicle;
};

private _hasDlc = (getAssetDLCInfo [_vehicle]) param [1, true, [false]];
private _dlcIcon = getText(configFile >> "CfgMods" >> (getText (_armaCfg >> "DLC")) >> "logo");

[
  _armaCfg,
  _missionCfg,
  getText(_armaCfg >> "picture"),
  getText(_armaCfg >> "displayName"),
  getNumber(_armaCfg >> "maxSpeed"),
  getNumber(_armaCfg >> "armor"),
  getNumber(_armaCfg >> "transportSoldier"),
  getNumber(_armaCfg >> "enginePower"),
  getNumber(_armaCfg >> "fuelCapacity"),
	[_hasDlc, _dlcIcon]
]