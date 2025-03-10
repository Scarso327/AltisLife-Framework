/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_shouldDoTutorial";

([] call ULP_fnc_isHobo && { [player, ["Civilian"]] call ULP_fnc_isFaction } && { ULP_FirstSpawn && { !isNil "ULP_DoTutorial" } || { [] call ULP_fnc_isOnTutorial } } && { !ULP_Imprisioned })