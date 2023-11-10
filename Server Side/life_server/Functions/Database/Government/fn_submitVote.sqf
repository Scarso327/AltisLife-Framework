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

// TODO: Increase amount if polling station has been rigged

[format["INSERT INTO votes (pid, candidate, amount) VALUES ('%1', '%2', '%3');", _steamid, _candidate select 0, _amount], 1] call DB_fnc_asyncCall;
["ElectionVoteSubmitted"] remoteExecCall ["ULP_fnc_invokeEvent", _voter];