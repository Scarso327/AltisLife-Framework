/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_submitVote";

_this params [
	["_pollingStation", objNull, [objNull]],
	["_voter", objNull, [objNull]],
	["_candidateSteamId", "", [""]]
];

private _steamid = getPlayerUID _voter;

if (isNull _voter || { _steamid isEqualTo "" }) exitWith { false };

private _candidates = [true] call ULP_SRV_fnc_getCandidates;

private _candidateIndex = _candidates findIf { (_x select 1) isEqualTo _candidateSteamId };

if (_candidateIndex isEqualTo -1) exitWith {
	["ElectionVoteSubmitted", ["You must select a valid candidate"]] remoteExecCall ["ULP_fnc_invokeEvent", _voter];
};

private _candidate = _candidates select _candidateIndex;
private _amount = 1;

private _riggedGroup = _pollingStation getVariable ["rigged_group", grpNull];

if !(isNull _riggedGroup && { ([_riggedGroup] call ULP_fnc_groupId) isEqualTo -1 }) then {
	private _steamIds = keys (_riggedGroup getVariable ["group_members", createHashMap]);

	if (_candidateSteamId in _steamIds) then {
		_amount = _amount + 1;
	};
};

[format["INSERT INTO votes (pid, candidate, amount) VALUES ('%1', '%2', '%3');", _steamid, _candidate select 0, _amount], 1] call DB_fnc_asyncCall;
["ElectionVoteSubmitted"] remoteExecCall ["ULP_fnc_invokeEvent", _voter];