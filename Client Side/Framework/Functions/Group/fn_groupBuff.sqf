/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_groupBuff";

(((_this param [0, group player, [grpNull]]) getVariable ["group_buffs", createHashMap]) getOrDefault [(_this param [1, "", [""]]), 0])