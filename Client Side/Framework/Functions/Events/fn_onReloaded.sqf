/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onReloaded";

_this params [
	["_unit", objNull, [objNull]],
	["_weapon", "", [""]],
	["_muzzle", "", [""]],
	["_newMagazine", [], [[]]],
	["_oldMagazine", [], [[]]]
];

private _weaponNonLethalCfg = missionConfigFile >> "CfgItems" >> _weapon >> "NonLethal";

if (isClass _weaponNonLethalCfg && { [getNumber (_weaponNonLethalCfg >> "hasTaserReload")] call ULP_fnc_bool } && { !ULPEvent_TaserFired }) then {
	_unit setAmmo [_weapon, 1];
};