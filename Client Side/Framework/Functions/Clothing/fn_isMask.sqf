/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isMask";

_this params [
	["_classname", "", [""]]
];

private _cfg = missionConfigFile >> "CfgClothing" >> _classname;
(isClass _cfg && { isNumber (_cfg >> "isMask") } && { getNumber (_cfg >> "isMask") isEqualTo 1 })