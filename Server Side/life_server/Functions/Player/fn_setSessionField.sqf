/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setSessionField";

_this params [
	["_unit", objNull, [objNull]],
	["_field", "", [""]],
	["_value", 0]
];

(_unit getVariable ["session", createHashMap]) set [_field, _value];