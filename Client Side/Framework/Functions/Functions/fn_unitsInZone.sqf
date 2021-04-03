/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_unitsInZone";

_this params [
	["_marker", "", [""]],
	["_units", [player], [[]]],
	["_factions", [], [[]]],
	["_condition", { true }, ["", {}]]
];

if (_condition isEqualType "") then {
	_condition = compile _condition;
};

((_units inAreaArray _marker) select {
	!(isNull _x) && 
	{ alive _x } && 
	{ !(isDowned(_x)) } &&
	{ isNull (objectParent _x) } &&
	{ (_x getVariable ["faction", ""]) in _factions } && 
	{ _x call _condition }
})