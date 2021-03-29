/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseOwner";

_this params [
	["_building", objNull, [objNull]],
	["_unit", player, [objNull]],
	["_group", true, [false]]
];

private _owner = _building getVariable ["building_owner", []];
([_building] call ULP_fnc_isHouse && { (_owner param [0, ""]) isEqualTo (getPlayerUID _unit) || { _group && { [_building] call ULP_fnc_isHouseShared && { ([group _unit] call ULP_fnc_groupId) isEqualTo (_owner param [1, -5]) } } } })