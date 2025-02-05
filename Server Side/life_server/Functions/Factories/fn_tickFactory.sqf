/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_tickFactory";

_this params [
	["_factory", objNull, [objNull]]
];

(_factory getVariable ["product_order", []]) params [
	"_product", "_requiredPower", "_quantity", "_tickTime"
];

if (isNull _factory || { _quantity <= 0 } || { _tickTime <= 0 } || { !isClass _product } || { !(_factory getVariable ["locked", false]) }) exitWith {};

private _factoryPower = _factory getVariable ["power", 0];

if (_factoryPower < _requiredPower) exitWith {
	_this call ULP_SRV_fnc_endFactory;
};

// Shouldn't be possible but just in case
private _cargoUser = _factory getVariable ["ULP_VirtualCargo_User", objNull];
if !(isNull _cargoUser) exitWith {
	_this call ULP_SRV_fnc_endFactory;
};

_quantity = [_factory, _product, _quantity] call (_factory getVariable "factory_onTick");

if (isNil "_quantity" || { _quantity isEqualTo 0 }) exitWith {
	_this call ULP_SRV_fnc_endFactory;
};

_factory setVariable ["product_order", [_product, _requiredPower, _quantity, _tickTime], true];

[_factory] call ULP_SRV_fnc_addFactoryTick;