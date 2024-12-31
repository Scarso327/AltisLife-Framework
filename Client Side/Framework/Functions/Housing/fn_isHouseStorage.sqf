/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseStorage";

_this params [
	["_container", objNull, [objNull]]
];

!(isNull _container && { isNil { _container getVariable "building" } })