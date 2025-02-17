/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startGroupAlliance";

_this params [
	["_groupA", grpNull, [grpNull]],
	["_groupB", grpNull, [grpNull]]
];

private _groupAId = [_groupA] call ULP_fnc_groupId;
private _groupBId = [_groupB] call ULP_fnc_groupId;

if (isNull _groupA || { isNull _groupB } || { _groupAId isEqualTo -1 } || { _groupBId isEqualTo -1 } || { _groupA isEqualTo _groupB }) exitWith {};

private _groupAName = [_groupA] call ULP_fnc_getGroupName;
private _groupBName = [_groupB] call ULP_fnc_getGroupName;

private _alliances = + (_groupA getVariable ["group_alliances", createHashMap]);
_alliances set [_groupBId, _groupBName];
_groupA setVariable ["group_alliances", _alliances, true];

private _groupBAlliances = + (_groupB getVariable ["group_alliances", createHashMap]);
_groupBAlliances set [_groupAId, _groupAName];
_groupB setVariable ["group_alliances", _groupBAlliances, true];

[_groupAId, _groupBId] call ULP_SRV_fnc_handleGroupAlliance;

["GroupAllianceStarted", [_groupAName]] remoteExecCall ["ULP_fnc_invokeEvent", units _groupA];
["GroupAllianceStarted", [_groupBName]] remoteExecCall ["ULP_fnc_invokeEvent", units _groupB];