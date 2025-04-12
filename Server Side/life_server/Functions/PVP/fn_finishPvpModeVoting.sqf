/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_finishPvpModeVoting";

if (isNil "ULP_SRV_PvpModes") exitWith {
	["PVP Mode vote finish failed because no vote is active..."] call ULP_fnc_logIt;
};

remoteExecCall ["", "PvpVoteStarted"]; // Remove JIP
["PvpVoteFinished", []] remoteExecCall ["ULP_fnc_invokeEvent", RANY];

private _votes = values (missionNamespace getVariable ["ULP_SRV_PvpVotes", createHashMap]);
private _winningMode = [];

{
	private _modeKey = _x;

	private _totalVotes = { _x isEqualTo _modeKey } count _votes;
	private _winningVotes = _winningMode param [1, 0];

	if (_totalVotes >= _winningVotes) then {
		_winningMode = [_y, _totalVotes];
	};
} forEach ULP_SRV_PvpModes;

private _currentPvpMode = _winningMode param [0, [], []];

_currentPvpMode params [
	["_mode", configNull, [configNull]],
	["_location", configNull, [configNull]]
];

if (isNull _mode || { isNull _location }) exitWith {
	["PVP Mode vote finish failed to find a winner..."] call ULP_fnc_logIt;
};

missionNamespace setVariable ["ULP_SRV_PvpModes", nil];
missionNamespace setVariable ["ULP_SRV_PvpVotes", nil];
missionNamespace setVariable ["ULP_PvpMode_VoteStartTime", nil, true];

missionNamespace setVariable ["ULP_SRV_CurrentPvpMode", _currentPvpMode, true];
missionNamespace setVariable ["ULP_SRV_CurrentScores", createHashMap, true];

private _onServerStart = compile getText (_mode >> "ServerEvents" >> "onStart");
private _onServerEnd = compile getText (_mode >> "ServerEvents" >> "onStop");

_location call _onServerStart;

[getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "maxDuration"), _onServerEnd, {
	if (isNil "ULP_SRV_CurrentPvpMode") exitWith {};

	[] call _this;

	missionNamespace setVariable ["ULP_SRV_CurrentScores", nil, true];
	missionNamespace setVariable ["ULP_SRV_CurrentPvpMode", nil, true];
}] call ULP_fnc_waitExecute;