/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getMaxLevel";

_this params [
	["_lvlCfg", missionConfigFile >> "CfgProgression" >> "Leveling", [configNull]]
];

if !(isClass _lvlCfg) exitWith { 0 };

(getNumber (_lvlCfg >> "maxLevel"))