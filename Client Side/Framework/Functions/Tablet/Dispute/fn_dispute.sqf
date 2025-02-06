/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_dispute";

_display = _this;
if (isNull _display) exitWith {};

[] call ULP_fnc_disputePlayer;
["Home"] call ULP_fnc_setScreen;