/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onPlayerRespawn";

_this params [
	["_unit", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

if !(isPlayer _unit) exitWith {};
