/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_removeEachFrame";

if !(_this params [
	["_index", -1, [0]]
]) exitWith { false };

ULP_eachFrameEvents deleteAt _index;
true