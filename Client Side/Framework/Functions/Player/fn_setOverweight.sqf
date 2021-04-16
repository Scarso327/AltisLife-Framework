/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setOverweight";

_this params [
	["_overweight", false, [true]]
];

if !((isForcedWalk player) isEqualTo _overweight) then {
	player forceWalk _overweight;
	player enableFatigue _overweight;
	player setFatigue ([0, 1] select _overweight);
};