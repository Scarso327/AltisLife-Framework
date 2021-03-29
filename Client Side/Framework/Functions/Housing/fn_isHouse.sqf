/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouse";

_this params [
	["_building", objNull, [objNull]]
];

(!(isNull _building) && { isClass (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _building)) })