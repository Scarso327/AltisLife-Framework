/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_isUnitsInZone";

_this params [
	["_marker", "", [""]],
	["_units", [player], [[]]]
];

_marker = toLower _marker;

(allMapMarkers findIf { 
	(toLower _x) find _marker > -1 
	&& { !((_units inAreaArray _x) isEqualTo []) } 
} > -1)