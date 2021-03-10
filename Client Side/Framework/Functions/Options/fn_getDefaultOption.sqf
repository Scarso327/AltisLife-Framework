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

switch (getText (_class >> "type")) do {
	case "DROPDOWN": {
		(getArray (_class >> "values") # 1) breakOut "fn_getDefaultOption";
	};
	default { 0 breakOut "fn_getDefaultOption"; }
};