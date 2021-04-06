/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isGroupMember";

((_this param [0, getPlayerUID player ,[""]]) in ((_this param [1, group player ,[grpNull]]) getVariable ["group_members", createHashMap]))