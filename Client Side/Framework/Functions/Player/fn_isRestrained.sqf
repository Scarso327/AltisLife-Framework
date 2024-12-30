/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isRestrained";

_this params [
	["_object", player, [objNull]]
];

!(isNull (_object getVariable ["restrained", objNull]))