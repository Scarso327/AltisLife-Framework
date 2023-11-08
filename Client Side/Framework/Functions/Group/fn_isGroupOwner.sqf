/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isGroupOwner";

_this params [
	["_unit", player, [objNull]]
];

(!(isNull _unit) && { (getPlayerUID _unit) isEqualTo ((group _unit) getVariable ["group_owner", ""]) })