/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_constant";

_this params [
	["_var", "", [""]],
	["_set", false, [true]],
	["_value", "false"]
];

private _curValue = missionNamespace getVariable _var;

if (_set) exitWith {
	if !(isNil "_curValue") exitWith { _curValue breakOut "fn_constant"; };
	compileFinal ([str _value, _value] select (_value isEqualType ""))
};

if (isNil "_curValue" || { !(_curValue isEqualType {}) }) exitWith { _curValue };
(call _curValue)