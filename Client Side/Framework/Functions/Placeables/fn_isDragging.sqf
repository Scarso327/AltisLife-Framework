/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isDragging";

_this params [
	["_unit", player, [objNull]]
];

(isNull _unit || { !((count ((attachedObjects _unit) select { !(isNull (_x getVariable ["unitDragging", objNull])) })) isEqualTo 0) })