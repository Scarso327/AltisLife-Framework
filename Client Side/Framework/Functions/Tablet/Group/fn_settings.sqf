/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_settings";

_display = _this;
if (isNull _display) exitWith {};

(_display displayCtrl 23088) ctrlSetStructuredText parseText format ["Group Tax<t align='right'>(%1%2)</t>", [] call ULP_fnc_groupTax, "%"];