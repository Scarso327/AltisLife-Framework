/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_destroyLayer";

_this params [
	["_name", "", [""]],
	["_fadeOutTime", 0, [0]],
	["_ignoreNullLayer", false, [true]]
];

if (isNull ([_name] call ULP_UI_fnc_getLayer) && { !_ignoreNullLayer }) exitWith { false };

_name cutFadeOut _fadeOutTime;
uiNamespace setVariable [_name, nil];

true