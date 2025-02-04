/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_tickFactory";

_this params [
	["_factory", objNull, [objNull]]
];

private _product = _factory getVariable ["product_order", configNull];
private _quantity =  _factory getVariable ["product_quantity", 0];
private _tickTime = _factory getVariable ["product_tick", 30];

if (isNull _factory || { _quantity <= 0 } || { _tickTime <= 0 } || { !isClass _product } || { !(_factory getVariable ["locked", false]) }) exitWith {};

// Shouldn't be possible but just in case
private _cargoUser = _factory getVariable ["ULP_VirtualCargo_User", objNull];
if !(isNull _cargoUser) exitWith {
	_this call ULP_SRV_fnc_endFactory;
};

private _materials = getArray (_product >> "materials");

{
	_x params ["_item", "_amount"];
	
	[_factory, _item, _amount, false] call ULP_fnc_removeFromCargo;
} forEach _materials;

[_factory, configName _product, 1, false, true] call ULP_fnc_addToCargo;

_quantity = _quantity - 1;

if (_quantity isEqualTo 0) exitWith {
	_this call ULP_SRV_fnc_endFactory;
};

_factory setVariable ["product_quantity", _quantity];

[_factory, _tickTime] call ULP_SRV_fnc_addFactoryTick;