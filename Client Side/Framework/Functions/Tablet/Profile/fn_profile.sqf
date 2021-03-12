/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_profile";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

private _toolbox = _display displayCtrl 23028;

switch (lbCurSel _toolbox) do {
	case 3: { ["PlayerTag"] call ULP_fnc_setScreen; };
	case 2: { ["Loyalty"] call ULP_fnc_setScreen; };
	case 1: { ["Achievements"] call ULP_fnc_setScreen; };
	default { ["Professions"] call ULP_fnc_setScreen; };
};