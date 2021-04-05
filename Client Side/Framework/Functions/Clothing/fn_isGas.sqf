/*
** Author: Lewis Mackinnon
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isGas";

_this params [
	["_classname", "", [""]]
];

private _cfg = missionConfigFile >> "CfgClothing" >> _classname;
(isClass _cfg && { isNumber (_cfg >> "isGas") } && { getNumber (_cfg >> "isGas") isEqualTo 1 })