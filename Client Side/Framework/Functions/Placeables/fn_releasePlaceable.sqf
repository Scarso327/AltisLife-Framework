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

// Reset Pos to Ground
private _pos = getPosATL _object;
_pos set[2, 0];

_object setPosATL _pos;
_object setVectorUp surfaceNormal _pos;

_unit playAction "released";