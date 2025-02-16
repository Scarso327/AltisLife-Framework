/*
** Author: Jack "Scarso" Farhall
** Description: Returns the required XP to reach the next perk level
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getPerkXPRequirement";

_this params [
	["_perk", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPerks" >> _perk >> "Leveling";
if !(isClass _cfg) exitWith { 0 };

private _level = (_this call ULP_fnc_getPerkLevel) select 0;
private _maxLevel = getNumber (_cfg >> "maxLevel");

if (_level isEqualTo _maxLevel) exitWith { 0 };

getNumber (_cfg >> "xpLevel")