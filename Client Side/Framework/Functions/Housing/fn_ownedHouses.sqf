/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_ownedHouse";

(ULP_Houses select {
	[_x, player, false] call ULP_fnc_isHouseOwner
})