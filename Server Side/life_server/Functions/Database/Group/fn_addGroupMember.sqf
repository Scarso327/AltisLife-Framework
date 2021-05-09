/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addGroupMember";

_this params [
	["_group", grpNull, [grpNull]],
	["_unit", objNull, [objNull]]
];

if (isNull _group || { isNull _unit }) exitWith {};

private _members = + (_group getVariable ["group_members", createHashMap]);
private _steamid = getPlayerUID _unit;

if !(_steamid in _members) then {
	_members set [_steamid, [name _unit, 0]];
	_group setVariable ["group_members", _members, true];
};

if ([_group, _unit] call ULP_fnc_joinGroup) then {
	[_steamid, [_group] call ULP_fnc_groupId] call ULP_SRV_fnc_setGroupId;
	["GroupJoined", [_unit]] remoteExecCall ["ULP_fnc_invokeEvent", units _group];
};