/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getDefaultOption";

_this params [
	["_option", "", [""]],
	["_category", "General", [""]]
];

private _class = missionConfigFile >> "CfgOptions" >> _category >> _option;
if !(isClass _class) exitWith {};

(getArray (_class >> "values") # 1) breakOut "fn_getDefaultOption";