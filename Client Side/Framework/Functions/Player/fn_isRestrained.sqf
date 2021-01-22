/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isRestrained";

if !(_this params [
	["_object", player, [objNull]]
]) exitWith { false };

!((_object getVariable ["restrained", sideUnknown]) isEqualTo sideUnknown)