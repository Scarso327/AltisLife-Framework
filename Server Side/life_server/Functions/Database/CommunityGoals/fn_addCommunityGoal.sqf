/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addCommunityGoal";

_this params [
	["_goalCfg", configNull, [configNull]]
];

if (isNull _goalCfg || { !(isClass _goalCfg) }) exitWith { [] };

private _id = ["community_goals"] call ULP_SRV_fnc_getNextId;
private _duration = getNumber (_goalCfg >> "duration");

[str parseText format["INSERT INTO `community_goals` (`id`, `goal_cfg`, `end_date`) VALUES ('%1', '%2', DATE_FORMAT(ADDDATE(CURDATE(), INTERVAL %3 DAY), '&#37;Y-&#37;c-&#37;e'));", [_id, ""] call ULP_fnc_numberText, configName _goalCfg, [_duration, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;

[_id, _goalCfg, _duration, 0]