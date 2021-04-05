/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isGroupPremium";

_this params [
	["_groupId", -1, [0]],
	["_group", group player, [grpNull]]
];

if (_groupId < 1) exitWith { false };

([_group] call ULP_fnc_groupId isEqualTo _groupId) && { (_group getVariable ["group_premium", false]) }