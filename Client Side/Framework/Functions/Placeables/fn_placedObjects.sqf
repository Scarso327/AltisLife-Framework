/*
** Author: Jack "Scarso" Farhall
** Description: Returns count of all objects placed by a certain player
*/
#include "..\..\script_macros.hpp"
scopeName "fn_placedObjects";

_this params [
	["_steamId", getPlayerUID player, [""]]
];

if (_steamId isEqualTo "") exitWith { 0 };

// Semi-Intensive - Will be a good idea to look into alternatives but only runs once when initially placing an objects so not high prio
count (vehicles select { ((_x getVariable ["object_owner", [""]]) param [0, "", [""]]) isEqualTo _steamId })