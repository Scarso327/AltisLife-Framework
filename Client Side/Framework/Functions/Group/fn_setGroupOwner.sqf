/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setGroupOwner";

_this params[
	["_group", grpNull, [grpNull, 0]], 
	["_unit", objNull, [objNull, ""]]
];

if (_group isEqualType 0) then {
	_group = [_group] call ULP_fnc_getGroupById;
};

if (isNull _group) exitWith { false };

private _steamid = _unit;
if (_unit isEqualType objNull) then {
	_steamid = getPlayerUID _unit;
};

private _members = + (_group getVariable ["group_members", createHashMap]);

if !(_steamid in _members) exitWith { false };

[_group, _unit, 6, false] call ULP_fnc_setGroupRank;
[_group, player, 5, false] call ULP_fnc_setGroupRank;

_group setVariable ["group_owner", _steamid, true];

[[_group] call ULP_fnc_groupId, getPlayerUID player, _steamid] remoteExecCall ["ULP_SRV_fnc_setGroupOwner", RSERV];

true