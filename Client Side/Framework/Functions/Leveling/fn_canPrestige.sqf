/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canPrestige";

(ULP_Level isEqualTo ([] call ULP_fnc_getMaxLevel) && // Max Level
	{ ULP_XP isEqualTo ([ULP_Level] call ULP_fnc_getRequiredXP) }) // Max XP