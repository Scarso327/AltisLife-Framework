/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_playerByUID";

_this params [
	["_uid", "", [""]]
];

(allPlayers param [ allPlayers findIf { (getPlayerUID _x) isEqualTo _uid }, objNull ])