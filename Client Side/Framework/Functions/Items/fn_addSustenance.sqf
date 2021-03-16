/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addSustenance";

_this params [
	["_item", "", [""]]
];

private _cfg = missionConfigFile >> "CfgVirtualItems" >> _item;
if !(isClass _cfg || { isClass (_cfg >> "Sustain") }) exitWith { false };

private _hunger = getNumber(_cfg >> "Sustain" >> "hunger");
private _thirst = getNumber(_cfg >> "Sustain" >> "thirst");

ULP_Survival_Hunger = 1 max ((ULP_Survival_Hunger + _hunger) min 100);
ULP_Survival_Thirst = 1 max ((ULP_Survival_Thirst + _thirst) min 100);

true