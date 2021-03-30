/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseOwned";

_this params [
	["_building", objNull, [objNull]]
];

!(isNil { _building getVariable "building_id" })