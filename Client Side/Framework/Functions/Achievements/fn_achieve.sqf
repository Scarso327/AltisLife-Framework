/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_achieve";

_this params [
	["_achievement", "", [""]]
];

private _cfg = missionConfigFile >> "CfgProgression" >> "CfgAchievements" >> _achievement;
if !(isClass _cfg) exitWith { false };

if ([_achievement] call ULP_fnc_hasAchieved) exitWith { false };

["AchievementUnlocked", [getText(_cfg >> "description")]] call BIS_fnc_showNotification;
playSound "FD_Finish_F";

private _leveling = getArray (_cfg >> "leveling");
if !(_leveling isEqualTo []) then { _leveling call ULP_fnc_addXP; };

ULP_Achievements pushBackUnique _achievement;
[player, 6, ULP_Achievements] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

true