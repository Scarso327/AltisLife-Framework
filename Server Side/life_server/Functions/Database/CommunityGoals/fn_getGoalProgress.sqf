/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getGoalProgress";

_this params [
	["_goalId", -1, [0]]
];

if (_goalId isEqualTo -1) exitWith { 0 };

private _query = [format ["SELECT COALESCE(SUM(`community_goal_contributions`.`contribution`), 0) FROM `community_goal_contributions` WHERE `goalId` = '%1'", 
	[_goalId, ""] call ULP_fnc_numberText], 2] call DB_fnc_asyncCall;

if !(_query isEqualType []) exitWith { 0 };

(_query param [0, 0])