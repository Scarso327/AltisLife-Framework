/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_groupRanks";

((_this param [0, group player, [grpNull]]) getVariable ["group_ranks", getArray (missionConfigFile >> "CfgGroups" >> "ranks")])