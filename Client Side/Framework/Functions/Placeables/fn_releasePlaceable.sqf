/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_releasePlaceable";

_this params [
	["_object", objNull, [objNull]]
];

private _unit = _object getVariable["unitDragging", objNull];
if (isNull _object || { isNull _unit }) exitWith {};

_object setVariable ["unitDragging", nil, true];
detach _object;

_unit playAction "released";