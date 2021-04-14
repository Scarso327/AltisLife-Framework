/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setGroupRank";

_this params [
	["_group", group player, [grpNull]],
	["_unit", player, [objNull, ""]],
	["_rank", 0, [0]]
];

if (_unit isEqualType objNull && { isNull _unit} || { _unit isEqualTo "" } || { !([_group] call ULP_fnc_isGroup) }) exitWith { false };

// Stop spam...
if (time < (_group getVariable ["rank_cooldown", 0])) exitWith {
	["You've changed this person's rank recently, please wait before trying again."] call ULP_fnc_hint;
	false
};
_group setVariable ["rank_cooldown", time + 3];

_rank = (_rank min 6) max 0;

private _steamid = _unit;
if !(_unit isEqualType "") then {
	_steamid = getPlayerUID _unit;
};

private _members = + (_group getVariable ["group_members", createHashMap]);
if !(_steamid in _members) exitWith { false };

private _value = _members getOrDefault [_steamid, []];
if !((_value param [1, 0]) isEqualTo _rank) then {
	_members set [_steamid, [_value param [0, ""], _rank]];
	_group setVariable ["group_members", _members, true];
	["GroupMembersChanged", [_members]] remoteExecCall ["ULP_fnc_invokeEvent", (units _group)];
};

if !(_unit isEqualType "") then {
	_unit setUnitRank (getArray (missionConfigFile >> "CfgGroups" >> "ranks") select _rank);
};
[_unit, 12, [[_group] call ULP_fnc_groupId, _rank]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
true