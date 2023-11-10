/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getCandidates";

_this params [
	["_isReturn", false, [true]]
];

private _candidates = [];

private _query = ["SELECT candidates.id, players.pid, candidates.name, groups.name, groups.type, groups.level FROM candidates INNER JOIN players ON players.pid = candidates.pid INNER JOIN groups ON groups.id = players.group_id WHERE candidates.active = '1' AND groups.active = '1'", 2, true] call DB_fnc_asyncCall;

if !(_query isEqualTo "" || { _query isEqualTo [] }) then {
	// Filter where groups don't have correct perk
	_candidates = _query select {
		_x params ["", "", "", "", "_groupType", "_groupLevel"];

		private _groupTypeCfg = missionConfigFile >> "CfgGroups" >> "Types" >> _groupType >> "Perks" >> "Governor";

		(isClass _groupTypeCfg && { getNumber (_groupTypeCfg >> "level") <= _groupLevel })
	};
};

if (isRemoteExecuted && { !_isReturn }) exitWith {
	["CandidatesReceived", [_candidates]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

_candidates