/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_rigPollingStation";

_this params [
	["_pollingStation", objNull, [objNull]],
	["_rigger", objNull, [objNull]]
];

if (isNull _pollingStation || { isNull _rigger }) exitWith {};

private _group = group _rigger;
private _groupId = [_group] call ULP_fnc_groupId;

if (_groupId isEqualTo -1 || { !(["PollRigging", _group] call ULP_fnc_hasGroupPerk) }) exitWith {
	["PollingStationRigged", ["You must be in a group with the ability to rig polling stations"]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

private _riggedGroup = _pollingStation getVariable ["rigged_group", grpNull];
private _riggedGroupId = [_riggedGroup] call ULP_fnc_groupId;

private _isRigged = !(isNull _riggedGroup && { _riggedGroupId isEqualTo -1 });

if (_isRigged && { _riggedGroupId isEqualTo _groupId }) exitWith {
	["PollingStationRigged", ["This polling station has already been rigged by your group"]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

[_group, "Rigging"] call ULP_SRV_fnc_addGroupXP;

_pollingStation setVariable ["rigged_group", _group, true];
["PollingStationRigged", ["You've successfully rigged this polling station"]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];