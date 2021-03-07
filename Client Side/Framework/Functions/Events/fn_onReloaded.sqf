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

if (_weapon in getArray(missionConfigFile >> "CfgSettings" >> "taserWeapons") && { !ULPEvent_TaserFired }) then {
	_unit setAmmo [_weapon, 1];
};