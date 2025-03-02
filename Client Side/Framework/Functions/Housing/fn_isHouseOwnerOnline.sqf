/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isHouseOwnerOnline";

_this params [
	["_object", objNull, [objNull]]
];

private _building = if ([_object] call ULP_fnc_isHouseStorage) then {
	_object getVariable "_container"
} else {
	_object
};

!((allPlayers findIf { [_building, _x] call ULP_fnc_isHouseOwner } ) isEqualTo -1)