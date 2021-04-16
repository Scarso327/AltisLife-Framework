/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isKindOf";

_this params [
	["_object", objNull, [objNull]],
	["_kinds", ["Car"], [[]]]
];

(!(isNull _object) && { _kinds findIf { _object isKindOf _x } > -1 })