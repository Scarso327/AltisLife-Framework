/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isATM";

_this params [
	["_object", cursorObject, [objNull]]
];

(!(isNull _object) && { ((str _object) find "atm_") > -1 } && { (player distance _object) <= 3 })