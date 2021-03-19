/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this] call ULP_fnc_addBank;
** 	[this, "Bank Account"] call ULP_fnc_addBank;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addBank";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "Cash Machine", [""]]
];

if (isNull _trader || { _title isEqualTo "" }) exitWith {};

_trader addAction [_title, { [] call ULP_fnc_openBank }, nil, 1.5, true, true, "", "true", 3];