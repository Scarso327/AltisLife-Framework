/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getGroupRank";

(getArray (missionConfigFile >> "CfgGroups" >> "ranks") find (rank (_this param [0, player, [objNull]])))