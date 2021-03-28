/*
** Author: Jack "Scarso" Farhall
** Description: Returns whether the provided group is an actual group (In database, etc)
*/
#include "..\..\script_macros.hpp"
scopeName "fn_groupId";

((_this param [0, group player, [grpNull]]) getVariable ["group_id", -1])