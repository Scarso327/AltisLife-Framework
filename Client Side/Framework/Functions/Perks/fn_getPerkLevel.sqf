/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getPerkLevel";

_this params [
	["_perk", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPerks" >> _perk;
if !(isClass _cfg) exitWith { [1, 0] };

(ULP_Perks getOrDefault [_perk, [1, 0]])