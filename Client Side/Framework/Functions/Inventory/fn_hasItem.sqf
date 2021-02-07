/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasItem";

if !(_this params [
	["_item", "", [""]]
]) exitWith { -1 };

ULP_Inventory getOrDefault [_item, -1]