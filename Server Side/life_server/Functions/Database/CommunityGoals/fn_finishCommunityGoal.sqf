/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_finishCommunityGoal";

_this params [
	["_id", -1, [0]],
	["_goalCfg", configNull, [configNull]],
	["_progress", 0, [0]]
];

if (_id isEqualTo -1 || { isNull _goalCfg }) exitWith {};

private _payout = ([_goalCfg, _progress] call ULP_fnc_getCommunityGoalPayout) param [0, 0, [0]];

private _contributions = [format ["SELECT `pid`, `contribution` FROM `community_goal_contributions` WHERE `goalId` = '%1'", [_id, ""] call ULP_fnc_numberText], 2, true] call DB_fnc_asyncCall;

if (_contributions isEqualType []) then {
	{
		_x params [ "_pid", "_contribution" ];

		private _myPayout = floor (_payout * (_contribution / (_progress max 1))); 

		if (_myPayout > 0) then {
			[_pid, "Money", "Community Goal Payout", _myPayout] call ULP_SRV_fnc_addMail;
		};
	} forEach _contributions;
};

[format[
	"UPDATE `community_goals` SET `paid`='1' WHERE `id` = '%1'", 
	[_id, ""] call ULP_fnc_numberText
], 1] call DB_fnc_asyncCall;

["CommunityGoalPaid", ["A Community Goal has been met and payout has been issued to your mail box if you contributed"]] remoteExecCall ["ULP_fnc_invokeEvent", RCLIENT];