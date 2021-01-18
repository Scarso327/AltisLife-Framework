/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_closeDialogs";

if !(canSuspend) exitWith { [] spawn ULP_UI_fnc_closeDialogs; };

while {dialog} do { closeDialog 0 };