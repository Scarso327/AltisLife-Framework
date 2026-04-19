/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\ulp_server\script_macros.hpp"
scopeName "fn_getSessionField";

_this params [
	["_unit", objNull, [objNull]],
	["_field", "", [""]]
];

((_unit getVariable ["session", createHashMap]) getOrDefault [_field, 0])