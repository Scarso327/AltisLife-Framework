/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_chance";

_this params [
	["_chance", 0, [0]]
];

if (_chance isEqualTo 0) exitWith { false };

(random 1 <= _chance)