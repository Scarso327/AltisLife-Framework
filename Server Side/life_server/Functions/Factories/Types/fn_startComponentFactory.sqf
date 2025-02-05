/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startComponentFactory";

_this params [
	["_factory", objNull, [objNull]],
	["_unit", objNull, [objNull]],
	["_productCfg", configNull, [configNull]],
	["_params", [], [[]]]
];

private _quantity = _params param [0, 0, [0]];
if (_quantity isEqualTo 0) exitWith {};

private _cargo = _factory getVariable ["ULP_VirtualCargo", createHashMap];
private _materials = getArray (_productCfg >> "materials");

private _possibleConversions = [];

{
	_x params ["_item", "_amount"];

	private _countInCargo = _cargo getOrDefault [_item, 0];
	_possibleConversions pushBack (floor (_countInCargo / _amount));
} forEach _materials;

private _maxPossibleQuantity = selectMin _possibleConversions;

if (_maxPossibleQuantity < _quantity) exitWith {
	["FactoryStarted", [
		format ["The factory only has enough materials to make <t color='#B92DE0'>%1</t> of that product while you requested <t color='#B92DE0'>%2</t>", _maxPossibleQuantity, _quantity]
	]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];

	0
};

_maxPossibleQuantity min _quantity