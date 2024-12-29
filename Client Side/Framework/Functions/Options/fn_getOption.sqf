/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getOption";

_this params [
	["_option", "", [""]],
	["_category", "General", [""]],
	["_default", false]
];

private _class = missionConfigFile >> "CfgOptions" >> _category >> _option;
if !(isClass _class) exitWith { _default };

if (_default isEqualType false) then {
	_default = [_option, _category] call ULP_fnc_getDefaultOption;
};

(missionProfileNamespace getVariable [format["ULP_Options_%1_%2", _category, _option], _default])