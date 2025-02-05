/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogFactory_PlaceOrder";

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
	["You don't have enough materials to place an order for this product"] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _maxPossibleQuantity], [_factory, _product],
	{
		_this params [
			["_factory", objNull, [objNull]],
			["_product", "", [""]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		if (_value isEqualTo 0) exitWith {
			["You can't place an order for 0 items to be made"] call ULP_fnc_hint;
		};

		["FactoryStarted", { 
			[_this param [0, ""]] call ULP_fnc_hint; 
		}, true] call ULP_fnc_addEventHandler; 
		
		[_factory, player, _product, [_value]] remoteExecCall ["ULP_SRV_fnc_startFactory", RSERV];
	}, false
] call ULP_fnc_selectNumber;