/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isOnTutorial";

_this params [
	["_unit", player, [objNull]]
];

(!isNull _unit && { _unit getVariable ["isOnTutorial", false] })