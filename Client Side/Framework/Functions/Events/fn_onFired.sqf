/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onFired";

_this params [
	["_unit", objNull, [objNull]],
	["_weapon", "", [""]],
	["_muzzle", "", [""]],
	["_mode", "", [""]],
	["_ammo", "", [""]],
	["_magazine", "", [""]],
	["_projectile", objNull, [objNull]],
	["_gunner", objNull, [objNull]]
];

// Protection to make sure we're happy they should be able to shoot
if !([_unit] call ULP_fnc_canFire) exitWith {
	deleteVehicle _projectile;
};

private _weaponNonLethalCfg = missionConfigFile >> "CfgItems" >> _weapon >> "NonLethal";

if (isClass _weaponNonLethalCfg && { [getNumber (_weaponNonLethalCfg >> "hasTaserReload")] call ULP_fnc_bool } && { !ULPEvent_TaserFired }) then {
	ULPEvent_TaserFired = true;
    _unit setAmmo [_weapon, 0];

    [1, [_unit, _weapon], { (_this select 0) setAmmo [(_this select 1), 1]; ULPEvent_TaserFired = false; }] call ULP_fnc_waitExecute;
};