/*
	@File: fn_setupClothing.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: addAction for clothing stores...
*/
#include "..\..\script_macros.hpp"
params [
	["_object", objNull, [objNull]],
	["_title", [], [[]]],
	["_shop", "", [""]],
	["_conditions", "", [""]]
];

if (isNull _object || {_shop isEqualTo ""} || {(count _title) != 2}) exitWith {
	diag_log format["[Shop Setup] Failed %1 %2", _shop, _title];
};

_object enableSimulation false;
_object allowDamage false;

private _colour = switch true do {
	case (_title select 0 isEqualTo "TPC"): {"#9fc5e8"};
	case (_title select 0 isEqualTo "CIV"): {"#b4a7d6"};
	case (_title select 0 isEqualTo "TAS"): {"#b6d7a8"};
	default {"#ffe599"};
};

_object addAction[
	format[
		"<t color='#9000ff'>[%2]</t> %1", 
		_title select 1, 
		_title select 0,
		_colour
	], LIFE(clothingMenu), _shop, 1.5, true, true, "", _conditions,
	5
];