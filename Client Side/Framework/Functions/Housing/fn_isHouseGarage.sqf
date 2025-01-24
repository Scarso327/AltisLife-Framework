/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseGarage";

_this params [
	["_building", objNull, [objNull]]
];

([_building] call ULP_fnc_isHouse && { isClass (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _building) >> "Garage") })