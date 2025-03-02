/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getTagPos";

_this params [
	["_object", objNull, [objNull]]
];

if (_object isKindOf "Man") exitWith {
	private _headPos = (_object selectionPosition "head");
	[(_headPos select 0) - 0.03, (_headPos select 1), (_headPos select 2) + 0.5]
};

[0, 0, ((0 boundingBoxReal _object select 1) select 2) * 1.5]