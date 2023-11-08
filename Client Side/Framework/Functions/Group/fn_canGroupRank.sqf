/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canGroupRank";

_this params [
	["_index", 0, [0]],
	["_unit", player, [objNull]]
];

([_unit] call ULP_fnc_isGroupOwner || { ([group _unit] call ULP_fnc_groupPermissions) param [_index, 0, [0]] <= [_unit] call ULP_fnc_getGroupRank })