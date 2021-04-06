/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_groupMembers";

_this params [
	["_group", group player, [grpNull]]
];

private _units = units _group;
private _online = createHashMap;
private _offline = + (_group getVariable ["group_members", createHashMap]);

{
	private _steamid = getPlayerUID _x;

	if (_steamid in _offline) then {
		_online set [_steamid, [name _x, [_x] call ULP_fnc_getGroupRank]];
		_offline deleteAt _steamid;
	};
} forEach _units;

[_online, _offline]