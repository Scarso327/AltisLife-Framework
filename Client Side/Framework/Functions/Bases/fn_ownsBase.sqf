/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_ownsBase";

_this params [
	["_base", "", [""]],
	["_unit", player, [objNull]]
];

private _obj = missionNamespace getVariable [format ["ULP_SRV_Base_%1", _base], objNull];
if (isNull _obj) exitWith { false };

private _group = group _unit;

([_group] call ULP_fnc_isGroup && { (_obj getVariable ["owner", -1]) isEqualTo ([_group] call ULP_fnc_groupId) })