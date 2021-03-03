/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyItems";

_this params [
	"_ctrl"
];

if !(canSuspend) exitWith { _this spawn ULP_fnc_buyItems; };

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _onItemBuy = getText((_display getVariable "storeCfg") >> "onItemBuy");
if (_onItemBuy isEqualTo "") exitWith {};

private _cartList = _display displayCtrl 3107;
if ((lbSize _cartList) isEqualTo 0) exitWith {
	hint "You must add something to your cart before you check out...";
};

_ctrl ctrlEnable false;

private _override = cbChecked (_display displayCtrl 3114);
private _cartValue = _display getVariable "cartValue";

if (CASH < _cartValue) then {
	hint "You can't afford these items...";
} else {
	private _itemsBought = 0;
	for "_i" from 0 to ((lbSize _cartList) - 1) do {
		private _data = _cartList lbData _i; // (str [_className, _texClass])
		_data = parseSimpleArray _data;

		_data params [
			"_className", "_texClass"
		];

		([_className] call ULP_fnc_itemCfg) params [
			"_cfgName",
			"_itemCfg" 
		];
		
		if ([_cartValue, _cartList, _className, _texClass, _cfgName, _itemCfg, _i, _override] call compile _onItemBuy) then {
			_itemsBought = _itemsBought + 1;
		} else {
			_cartValue = _cartValue - (_cartList lbValue _i);
		};
	};

	if !(_itemsBought isEqualTo 0) then {
		// Wipe Cart...
		lbClear _cartList;
		_cartList lbSetCurSel -1;

		// Pay for it and wipe total value...
		CASH = CASH - _cartValue;
		_display setVariable ["cartValue", 0];
		[] call ULP_fnc_syncPlayerInfo;

		// Update inventory view if it's visible...
		if (ctrlShown (_display displayCtrl 3112)) then {
			[_ctrl, 1] call ULP_fnc_switchInventory;
		};

		hint format["You've bought these items for £%1", [_cartValue] call ULP_fnc_numberText];
	} else {
		hint "You don't have enough space for these items...";
	};
};

_ctrl ctrlEnable true;