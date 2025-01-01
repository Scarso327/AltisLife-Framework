/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseStorage";

_this params [
	["_container", objNull, [objNull]]
];

!(isNil { _container getVariable "building" })