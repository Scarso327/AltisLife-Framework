/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setTags";

_this params [
	["_object", objNull, [objNull]]
];

if (isNull _object) exitWith {};

getArray(missionConfigFile >> "CfgTags" >> (["baseColour", "friendColour"] select (!(isNull _object) && { _object in (units (group player)) })))