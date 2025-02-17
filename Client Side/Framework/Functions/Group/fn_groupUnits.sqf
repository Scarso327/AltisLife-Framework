
/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_groupUnits";

private _group = _this param [0, group player, [grpNull]];

private _units = units _group;
private _allies = [_group] call ULP_fnc_alliedGroups;

{
	_units append (units _x);
	nil
} count _allies;

_units