/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_endGroupAlliance";

_this params [
	["_groupA", grpNull, [grpNull]],
	["_groupBId", -1, [0]]
];

private _groupAId = [_groupA] call ULP_fnc_groupId;
if (isNull _groupA || { _groupAId isEqualTo -1 } || { _groupBId isEqualTo -1 }) exitWith {};

private _alliances = + (_groupA getVariable ["group_alliances", createHashMap]);

private _groupBName = _alliances getOrDefault [_groupBId, ""];
if (_groupBName isEqualTo "") exitWith {}; // We don't have an alliance?

private _groupB = [_groupBId] call ULP_fnc_getGroupById;

_alliances deleteAt _groupBId;
_groupA setVariable ["group_alliances", _alliances, true];

if !(isNull _groupB) then {
	private _groupBAlliances = + (_groupB getVariable ["group_alliances", createHashMap]);

	_groupBAlliances deleteAt _groupAId;

	_groupB setVariable ["group_alliances", _groupBAlliances, true];

	["GroupAllianceEnded", [[_groupA] call ULP_fnc_getGroupName]] remoteExecCall ["ULP_fnc_invokeEvent", units _groupB];
};

[_groupAId, _groupBId, true] call ULP_SRV_fnc_handleGroupAlliance;

["GroupAllianceEnded", [_groupBName]] remoteExecCall ["ULP_fnc_invokeEvent", units _groupA];