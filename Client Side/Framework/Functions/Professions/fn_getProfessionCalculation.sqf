/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getProfessionCalculation";

_this params [
	["_profession", "", [""]]
];

private _cfg = missionConfigFile >> "CfgProfessions" >> _profession;
if !(isClass _cfg) exitWith { 0 };

((ULP_Professions getOrDefault [_profession, [0, 0]]) call compile getText (_cfg >> "effectCalculation"))