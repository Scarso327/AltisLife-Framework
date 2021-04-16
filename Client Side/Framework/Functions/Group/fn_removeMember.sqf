/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeMember";

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

_members deleteAt _steamid;
_group setVariable ["group_members", _members, true];

["GroupMembersChanged", [_members]] remoteExecCall ["ULP_fnc_invokeEvent", (units _group)];

[_steamid, -1] remoteExecCall ["ULP_SRV_fnc_setGroupId", RSERV];

if !(_unit isEqualType "") then {
	[_unit] joinSilent (createGroup [side _unit, true]);
};

true