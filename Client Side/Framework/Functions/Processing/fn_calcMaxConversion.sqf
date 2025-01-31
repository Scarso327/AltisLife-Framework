/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_calcMaxConversion";

_this params [
	["_materials", [], []]
];

private _possibleConversions = [];

{
	_possibleConversions pushBack (floor (([_x select 0] call ULP_fnc_hasItem) / (_x select 1)));
} forEach _materials;

selectMin _possibleConversions