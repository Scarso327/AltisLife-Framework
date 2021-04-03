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

((allMapMarkers select { [_marker, _x] call ULP_fnc_inString }) findIf { (count (_units inAreaArray _x)) > 0 } > -1)