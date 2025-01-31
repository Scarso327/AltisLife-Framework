/*
** Author: Jack "Scarso" Farhall
** Description: Returns the max number of items you can add for this item.
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getMaxQuantity";

_this params [
	["_weight", 0, [0]]
];

( floor (([] call ULP_fnc_freeCarry) / _weight) max 0 )