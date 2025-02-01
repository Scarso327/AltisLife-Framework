/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_startProgress";

if (canSuspend) exitWith {
    [ULP_UI_fnc_startProgress, _this] call ULP_fnc_directCall;
};

private _duraction = _this param [1, 30, [0]];

if ([] call ULP_UI_fnc_isProgress || { _duraction <= 0 }) exitWith {
	false
};

(["RscProgress", "PLAIN", 3, _this] call ULP_UI_fnc_createLayer)