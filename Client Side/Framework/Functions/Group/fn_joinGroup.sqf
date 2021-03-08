/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_joinGroup";

_this params[
	["_group", grpNull, [grpNull, 0]], 
	["_unit", objNull, [objNull]]
];

if (_group isEqualType 0) then {
	_group = [_group] call ULP_fnc_getGroupById;
};

if (isNull _unit || { isNull _group }) exitWith { false };

[_unit] joinSilent _group;
true