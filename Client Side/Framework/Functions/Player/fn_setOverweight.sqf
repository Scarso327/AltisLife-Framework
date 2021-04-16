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
	player forceWalk _isOverWeight;
	player enableFatigue _isOverWeight;
	player setFatigue ([0, 1] select _isOverWeight);
};