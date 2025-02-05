/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_tickComponentFactory";

_this params [
	["_factory", objNull, [objNull]],
	["_product", configNull, [configNull]],
	["_quantity", 0, [0]]
];

private _materials = getArray (_product >> "materials");

{
	_x params ["_item", "_amount"];
	
	[_factory, _item, _amount, false] call ULP_fnc_removeFromCargo;
} forEach _materials;

[_factory, configName _product, 1, false, true] call ULP_fnc_addToCargo;

_quantity - 1