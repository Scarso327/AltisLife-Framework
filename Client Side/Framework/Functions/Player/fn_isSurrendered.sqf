/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isSurrendered";

_this params [
	["_object", player, [objNull]]
];

(_object getVariable ["surrender", false])