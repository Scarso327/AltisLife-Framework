/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isNightVision";

_this params [
	["_classname", "", [""]]
];

private _cfg = missionConfigFile >> "CfgClothing" >> _classname;
(isClass _cfg && { isNumber (_cfg >> "isNV") } && { [getNumber (_cfg >> "isNV")] call ULP_fnc_bool })