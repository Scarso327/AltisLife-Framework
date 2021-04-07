/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_reputationPrice";

_this params [
	["_price", 0, [0]]
];

if (_price < 1) exitWith { _price };

round (_price - (_price * ((floor (ULP_Reputation / 100) / 100) * 2)))