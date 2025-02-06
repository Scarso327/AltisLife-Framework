/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseOwnerOnline";

_this params [
	["_building", objNull, [objNull]]
];

!((allPlayers findIf { [_building, _x] call ULP_fnc_isHouseOwner } ) isEqualTo -1)