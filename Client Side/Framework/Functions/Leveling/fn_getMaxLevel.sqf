/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getMaxLevel";

private _lvlCfg = missionConfigFile >> "CfgProgression" >> "Leveling";
if !(isClass _lvlCfg) exitWith { 0 };

(getNumber (_lvlCfg >> "maxLevel"))