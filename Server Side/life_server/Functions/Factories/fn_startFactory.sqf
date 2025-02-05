/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startFactory";

_this params [
	["_factory", objNull, [objNull]],
	["_unit", objNull, [objNull]],
	["_product", "", [""]],
	["_quantity", 0, [0]]
];

private _factoryCfgName = _factory getVariable ["factory", ""];

private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> _factoryCfgName;
private _productCfg = _factoryCfg >> "Products" >> _product;

if (isNull _factory || { isNull _unit } || { _quantity <= 0 } || { !isClass _productCfg } || { _factoryCfgName isEqualTo "" }) exitWith {};

private _requiredPower = if (isNumber (_productCfg >> "requiredPower")) then {
	getNumber (_productCfg >> "requiredPower")
} else {
	getNumber (_factoryCfg >> "requiredPower")
};

private _factoryPower = _factory getVariable ["power", 0];

if (_factoryPower < _requiredPower) exitWith {
	["FactoryStarted", [
		format ["This product requires <t color='#B92DE0'>tier %1</t> power, this factory currently has <t color='#B92DE0'>tier %2</t> power.", _requiredPower, _factoryPower]
	]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

private _cooldown = _factory getVariable ["cooldown", 0];
if (_cooldown > serverTime) exitWith {
	["FactoryStarted", [
		format ["The factory has recently finished an order and is on cooldown, it's be available in <t color='#B92DE0'>%1</t> seconds.", [round (_cooldown - serverTime)] call ULP_fnc_numberText]
	]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

if (_factory getVariable ["locked", false]) exitWith {
	["FactoryStarted", ["The factory is already processing a request"]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

_factory setVariable ["locked", true, true];

private _cargoUser = _factory getVariable ["ULP_VirtualCargo_User", objNull];
if !(isNull _cargoUser) exitWith {
	_factory setVariable ["locked", nil, true];
	["FactoryStarted", ["Someone is accessing the storage so the factory can't start"]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

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
	_factory setVariable ["locked", nil, true];
	["FactoryStarted", [
		format ["The factory only has enough materials to make <t color='#B92DE0'>%1</t> of that product while you requested <t color='#B92DE0'>%2</t>", _maxPossibleQuantity, _quantity]
	]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

_factory setVariable ["product_order", _productCfg];
_factory setVariable ["product_power", _requiredPower];
_factory setVariable ["product_quantity", _maxPossibleQuantity min _quantity];
_factory setVariable ["product_tick", getNumber (_productCfg >> "tickTime")];

private _source = createSoundSource ["Factory_Processing", getPosATL _factory, [], 0];
_factory setVariable ["sound", _source];

[_factory] call ULP_SRV_fnc_addFactoryTick;

["FactoryStarted", [format ["Your order is being processed."]]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];