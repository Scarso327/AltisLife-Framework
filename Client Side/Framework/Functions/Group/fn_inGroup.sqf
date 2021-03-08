/*
** Author: Jack "Scarso" Farhall
** Description: Returns whether the provided unit is in the provided group.
*/
#include "..\..\script_macros.hpp"
scopeName "fn_inGroup";

_this params[
	["_group", grpNull, [grpNull, 0]], 
	["_unit", objNull, [objNull]]
];

if (_group isEqualType 0) then {
	_group = [_group] call ULP_fnc_getGroupById;
};

if (isNull _unit || { isNull _group }) exitWith { false };

((group _unit) isEqualTo _group)