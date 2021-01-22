/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addItems";

_this params [
	["_items", [], [[]]]
];

if (_items isEqualTo []) exitWith {};

{ player addItem _x; } forEach (_items select {
	player canAdd _x
});