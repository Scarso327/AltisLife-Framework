/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isKnocked";

_this params [
	["_object", player, [objNull]]
];

(_object getVariable ["knocked", false])