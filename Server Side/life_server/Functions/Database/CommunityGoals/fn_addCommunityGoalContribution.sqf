/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addCommunityGoalContribution";

_this params [
	["_contributor", objNull, [objNull]],
	["_goalObj", objNull, [objNull]],
	["_amount", 0, [0]]
];

private _steamId = getPlayerUID _contributor;
if (isNull _contributor || { _steamId isEqualTo "" } || { isNull _goalObj } || { _goalObj getVariable ["complete", false] } || { _amount < 1 }) exitWith {};

private _goalId = _goalObj getVariable ["id", -1];
private _config = _goalObj getVariable ["config", configNull];

private _progress = [_goalId] call ULP_SRV_fnc_getGoalProgress;

private _tiers = getArray (_config >> "tiers");
private _max = _tiers param [((count _tiers) - 1), 0, [0]]; 

private _contribution = _amount - ((_amount - (_max - _progress)) max 0);

private _newProgress = ((_progress + _contribution) min _max);
private _complete = _newProgress isEqualTo _max;

private _querySafeGoalId = [_goalId, ""] call ULP_fnc_numberText;

private _query = [format ["SELECT COALESCE(SUM(community_goal_contributions.contribution), 0) AS contributions FROM community_goal_contributions WHERE goalId = '%1' AND pid = '%2'", 
	_querySafeGoalId, _steamId], 2] call DB_fnc_asyncCall;

if !(_query isEqualType []) then { _query = []; };

private _currentContribution = _query param [0, 0, [0]];

if (_currentContribution isEqualTo 0) then {
	[format["INSERT INTO community_goal_contributions (pid, goalId, contribution) VALUES ('%1', '%2', '%3');", 
		_steamId, _querySafeGoalId, [_contribution, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
} else {
	[format[
		"UPDATE community_goal_contributions SET contribution='%3' WHERE goalId = '%1' AND pid = '%2'", 
		_querySafeGoalId, _steamId, [(_currentContribution + _contribution), ""] call ULP_fnc_numberText
	], 1] call DB_fnc_asyncCall;
};

if (_complete) then {
	_goalObj setVariable ["complete", true, true];

	// Delay of 5 seconds is a little over kill but it ensures previous updates filter in
	[5, [_goalId, _config, _newProgress], {
		_this call ULP_SRV_fnc_finishCommunityGoal;
	}] call ULP_fnc_waitExecute;
};