/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openTablet";

private _effectBlur = ppEffectCreate ["DynamicBlur", 300]; 
_effectBlur ppEffectEnable true; 
_effectBlur ppEffectAdjust [2.5]; 
_effectBlur ppEffectCommit 1.5; 
 
private _id = [[_effectBlur, {}]] call ULP_fnc_createEffect;

if (createDialog "RscTablet") then {
	private _display = findDisplay 23000;
	if (isNull _display) exitWith {};

	_display setVariable ["blur", _id];

	_display displaySetEventHandler ["keyDown","_this call ULP_fnc_rebindEsc"];

	["Home"] call ULP_fnc_setScreen;
};