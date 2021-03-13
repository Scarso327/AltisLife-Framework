/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasAchieved";

_this params [
	["_achievement", "", [""]]
];

if !(isClass (missionConfigFile >> "CfgProgression" >> "CfgAchievements" >> _achievement)) exitWith { false };

(_achievement in ULP_Achievements)