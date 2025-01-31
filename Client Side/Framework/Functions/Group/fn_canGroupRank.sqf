/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canGroupRank";

_this params [
	["_permission", "", [""]],
	["_unit", player, [objNull]]
];

private _requiredPerm = ([group _unit] call ULP_fnc_groupPermissions) getOrDefault [_permission, 0];

([_unit] call ULP_fnc_isGroupOwner || { _requiredPerm <= [_unit] call ULP_fnc_getGroupRank })