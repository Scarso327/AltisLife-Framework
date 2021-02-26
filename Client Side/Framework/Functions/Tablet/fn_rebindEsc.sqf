/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_rebindEsc";

private _display = findDisplay 23000;
if (isNull _display) exitWith { false };

private _screen = _display getVariable ["screen", "Home"];

if !(_screen isEqualType "") then {
	_screen = configName _screen;
};

if ((_this select 1) isEqualTo 1 && { !(_screen isEqualTo "Home") }) exitWith {
	[(_display getVariable ["preScreen", "Home"])] call ULP_fnc_setScreen;
	true
};

false