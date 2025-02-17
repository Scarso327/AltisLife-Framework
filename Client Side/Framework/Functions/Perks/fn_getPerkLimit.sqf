/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getPerkLimit";

// Every 5 levels you get another slot...
private _limit = getNumber (missionConfigFile >> "CfgPerks" >> "baseLimit") + (floor (ULP_Level / 5) max 0);

// Every 2 prestige levels you get another slot... (Oh and ensure we add a cap so it doesn't get stupid...)
((_limit + ULP_Prestige) min getNumber (missionConfigFile >> "CfgPerks" >> "maxLimit"))