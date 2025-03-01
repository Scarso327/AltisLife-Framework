/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_ownsSite";

_this params [
	["_location", objNull, [objNull, ""]],
	["_unit", player, [objNull]]
];

if (_location isEqualType "") then { _location = missionNamespace getVariable [_location, objNull]; };

if (isNull _location) exitWith { false };

private _group = group _unit;

([_group] call ULP_fnc_isGroup && { (_location getVariable ["site_owner_id", -1]) isEqualTo ([_group] call ULP_fnc_groupId) })