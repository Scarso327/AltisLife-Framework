/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseShared";

_this params [
	["_building", objNull, [objNull]]
];

([_building] call ULP_fnc_isHouse && { (_building getVariable ["building_shared", false]) })