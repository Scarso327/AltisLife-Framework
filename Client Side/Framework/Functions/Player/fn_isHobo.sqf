/*
** Author: Jack "Scarso" Farhall
** Description: Check if they're a new player
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHobo";

BANK <= 1000000 && { ULP_Level <= 3 } && { !(["Rebel"] call ULP_fnc_hasLicense) }