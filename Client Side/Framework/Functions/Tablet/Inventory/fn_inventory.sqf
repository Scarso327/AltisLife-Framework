/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_inventory";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

private _toolbox = _display displayCtrl 23014;

switch (lbCurSel _toolbox) do {
	case 2: { ["Crafting"] call ULP_fnc_setScreen; };
	case 1: { ["Licenses"] call ULP_fnc_setScreen; };
	default { ["VirtualInventory"] call ULP_fnc_setScreen; };
};