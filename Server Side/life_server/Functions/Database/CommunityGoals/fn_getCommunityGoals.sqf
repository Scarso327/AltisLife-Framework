/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getCommunityGoals";

_this params [
	["_unit", objNull, [objNull]]
];

private _goals = [];

private _steamid = getPlayerUID _unit;
if !(_steamid isEqualTo "") then {

	// TODO: Optimise down into a single query with a filter for factions

	private _query = [format ["SELECT community_goals.id, community_goal_contributions.contribution FROM community_goals INNER JOIN community_goal_contributions ON community_goals.id = community_goal_contributions.goalId WHERE community_goal_contributions.pid = '%1'", _steamid], 2, true] call DB_fnc_asyncCall;

	if !(_query isEqualType []) then { _query = []; };
	
	private _myContributions = createHashMapFromArray _query;

	{
		{
			private _goalId = _x getVariable ["id", -1];
			private _config = _x getVariable ["config", configNull];
			private _daysLeft = _x getVariable ["days_left", 0];

			if (_goalId isEqualTo -1 || { isNull _config } || { !([_unit, getArray (_config >> "factions")] call ULP_fnc_isFaction) } ) exitWith {};

			private _progress = [_goalId] call ULP_SRV_fnc_getGoalProgress;
			private _myProgress = _myContributions getOrDefault [_goalId, 0];

			_goals pushBack [configName _config, _progress, _myProgress, _daysLeft];
		} forEach _y;
	} forEach + (missionNamespace getVariable ["ULP_CommunityGoals", createHashMap]);
};

["CommunityGoalsReceived", [_goals]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];