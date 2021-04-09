/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getTagColour";

_this params [
	["_object", objNull, [objNull]],
	["_allowCustom", true, [false]]
];

if (isNull _object) exitWith {};

private _colour = _object getVariable ["colour", ""];
if (_allowCustom && { !(_colour isEqualTo "") }) exitWith { _colour };

getArray(missionConfigFile >> "CfgTags" >> (["baseColour", "friendColour"] select (!(isNull _object) && { _object in (units (group player)) })))