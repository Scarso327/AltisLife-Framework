/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sellItem";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _invList = _display displayCtrl 3112;
if ((lbSize _invList) isEqualTo 0) exitWith {
	hint "You don't have anything in your inventory to sell...";
};

_ctrl ctrlEnable false;

private _selItem = lbCurSel _invList;
if (_selItem isEqualTo -1) exitWith {
	hint "You must select an item from your inventory to sell...";
};

private _itemValue = _invList lbValue _selItem;
private _itemClass = _invList lbData _selItem;

if (_itemClass isEqualTo "" || { _itemValue < 0 }) exitWith {
	hint "This item can't be sold...";
};

[_itemClass, false] call life_fnc_handleItem;

_invList lbDelete _selItem;
_invList lbSetCurSel -1;

CASH = CASH + _itemValue;
[] call ULP_fnc_syncPlayerInfo;

hint format["You sold %1 for £%2", (_itemCfg select 5), [_itemValue] call ULP_fnc_numberText];

_ctrl ctrlEnable true;