/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogVehicleFactory_PlaceOrder";

_this params [ "_button" ];

if (isNull _button) exitWith {};

private _display = ctrlParent _button;

private _factory = _display getVariable ["factory", objNull];

private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> (_factory getVariable ["factory", ""]);
if !(isClass _factoryCfg) exitWith {};

private _product = _display getVariable ["selected_product", ""];
private _productCfg = _factoryCfg >> "Products" >> _product;

if (_product isEqualTo "" || { !isClass _productCfg }) exitWith { ["You must select a product to place an order for"] call ULP_fnc_hint; };

private _cargo = _factory getVariable ["ULP_VirtualCargo", createHashMap];
private _materials = getArray (_productCfg >> "materials");

private _possibleConversions = [];

{
	_x params ["_item", "_amount"];

	private _countInCargo = _cargo getOrDefault [_item, 0];
	_possibleConversions pushBack (floor (_countInCargo / _amount));
} forEach _materials;

private _maxPossibleQuantity = selectMin _possibleConversions;

if (_maxPossibleQuantity isEqualTo 0) exitWith {
	["The factory doesn't have enough materials to place an order for this product. You can press <t color='#B92DE0'>T</t> to place items into it."] call ULP_fnc_hint;
};

["FactoryStarted", { 
	[_this param [0, ""]] call ULP_fnc_hint; 
}, true] call ULP_fnc_addEventHandler; 

[_factory, player, _product, []] remoteExecCall ["ULP_SRV_fnc_startFactory", RSERV];