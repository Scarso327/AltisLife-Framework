/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_checkPower";

_this params [
	["_power", "", [""]],
	["_hint", true, [false]]
];

if (isNil "ULP_Staff" || { isNil "ULP_Event" }) exitWith { false };

private _cfg = missionConfigFile >> "CfgAdmin" >> "Power" >> _power;

private _hasAccess = (isClass _cfg && { call compile getText (_cfg >> "condition") });

if (!(_hasAccess) && { _hint } && { isText (_cfg >> "message") }) then {
	[getText (_cfg >> "message")] call ULP_fnc_hint;
};

_hasAccess