/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getPerkLimit";

private _limit = getNumber (missionConfigFile >> "CfgPerks" >> "baseLimit");

// Every 10 levels you get another slot...
if ((ULP_Level % 10) isEqualTo 0) then {
	_limit = round (ULP_Level / 10);
};

// Every 2 prestige levels you get another slot... (Oh and ensure we add a cap so it doesn't get stupid...)
((_limit + floor (ULP_Prestige / 2)) min getNumber (missionConfigFile >> "CfgPerks" >> "maxLimit"))