/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_handleItem";

_this params [
	["_item", "", [""]],
	["_quantity", 0, [1]],
	["_remove", false, [true]],
	["_ignoreCarry", false, [true]]
];

private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _item;
if !(isClass _itemCfg || { _quantity > 0 }) exitWith { false };

private _weight = getNumber (_itemCfg >> "weight") * _quantity;

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];

private _curTotal = [_item] call ULP_fnc_hasItem;
if (_curTotal isEqualTo -1) then { _curTotal = 0 };

if (_remove) then {
	private _newWeight = _carryWeight - _weight;
	private _newTotal = _curTotal - _quantity;

	if (_newTotal < 0) exitWith { false breakOut "fn_handleItem" };

	if (_newTotal isEqualTo 0) then {
		ULP_Inventory deleteAt _item;
	} else {
		ULP_Inventory set [_item, _newTotal];
	};

	ULP_CarryInfo set [0, _newWeight];
} else {
	private _newWeight = _carryWeight + _weight;
	if (!_ignoreCarry && { _newWeight > _maxWeight }) exitWith { false breakOut "fn_handleItem" };

	ULP_Inventory set [_item, _curTotal + _quantity];
	ULP_CarryInfo set [0, _newWeight];
};

true