/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setOverweight";

private _overweight = ULP_CarryWeight > ([] call ULP_fnc_maxCarry);

if !((isForcedWalk player) isEqualTo _overweight) then {
	player forceWalk _overweight;
	player enableFatigue _overweight;
	player setFatigue ([0, 1] select _overweight);
	
	if (_overweight) then { ["Overweight"] call ULP_fnc_achieve; };
};