/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getTagIcon";

_this params [
	["_object", objNull, [objNull]]
];

if (_object getVariable ["isHobo", false]) exitWith { "Data\Tags\hobo.paa" };

(_object getVariable ["icon", ""])