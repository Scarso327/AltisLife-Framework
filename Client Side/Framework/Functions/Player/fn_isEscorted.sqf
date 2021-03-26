/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isEscorted";

_this params [
	["_target", player, [objNull]]
];

!(isNull (attachedTo _target))