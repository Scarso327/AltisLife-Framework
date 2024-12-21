/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_clearHints";

if (canSuspend) exitWith {
    [ULP_fnc_hint, _this] call ULP_fnc_directCall;
};

[format["Clear hints called for display %1", _this], true] call ULP_fnc_logIt;

private _display = _this;
if (isNull _display) exitWith {};

{
	ctrlDelete _x;
} forEach + (_display getVariable ["hints", []]);

_display setVariable ["hints", nil];