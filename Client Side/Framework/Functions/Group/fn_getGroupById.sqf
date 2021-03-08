/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getGroupById";

_this params [
	["_groupid", 0, [0]]
];

allGroups param [allGroups findIf {
    _x getVariable["group_id", -1] isEqualTo _groupid
}, grpNull];