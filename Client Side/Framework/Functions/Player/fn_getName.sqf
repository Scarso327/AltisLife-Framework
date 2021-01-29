/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getName";

_this params [
	["_object", objNull, [objNull]]
];

if (_object isKindOf "Man") exitWith { name _object };
_object getVariable ["name", ""];