/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_createLayer";

_this params [
	["_name", "", [""]],
	["_type", "PLAIN", [""]],
	["_fadeInTime", 0, [0]]
];

if !(isNull ([_name] call ULP_UI_fnc_getLayer)) exitWith { false };

_name cutRsc [_name, _type, _fadeInTime];

true