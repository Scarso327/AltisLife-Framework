/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_group";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

private _toolbox = _display displayCtrl 23061;

switch (lbCurSel _toolbox) do {
	case 2: { ["GroupSettings"] call ULP_fnc_setScreen; };
	case 1: { ["GroupProgression"] call ULP_fnc_setScreen; };
	default { ["GroupOverview"] call ULP_fnc_setScreen; };
};