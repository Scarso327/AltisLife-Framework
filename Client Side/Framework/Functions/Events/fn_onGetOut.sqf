/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onGetOut";

_this params [
	["_unit", objNull, [objNull]],
	["_role", "", [""]],
	["_vehicle", objNull, [objNull]],
	["_turret", [], [[]]]
];

_unit setVariable ["seatbelt", false];

true