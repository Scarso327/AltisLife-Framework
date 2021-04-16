/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sellItem";

_this params [
	"_ctrl"
];

if ([[player] call ULP_fnc_getFaction, "physical"] call ULP_fnc_factionFree) exitWith {
	hint "Your gear is covered by the government and so you're unable to sell anything...";
};

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _invList = _display displayCtrl 3112;
if ((lbSize _invList) isEqualTo 0) exitWith {
	["You don't have anything in your inventory to sell!"] call ULP_fnc_hint;
};

_ctrl ctrlEnable false;

private _selItem = lbCurSel _invList;
if (_selItem isEqualTo -1) exitWith {
	["You must select an item from your inventory to sell!"] call ULP_fnc_hint;
};

private _itemValue = _invList lbValue _selItem;
private _itemClass = _invList lbData _selItem;

if (_itemClass isEqualTo "" || { _itemValue < 0 }) exitWith {
	["This item can't be sold!"] call ULP_fnc_hint;
};

[_itemClass, false] call life_fnc_handleItem;

_invList lbDelete _selItem;
_invList lbSetCurSel -1;

[_itemValue, false, format["Sold %1", (_itemCfg select 5)]] call ULP_fnc_addMoney;
[] call ULP_fnc_syncPlayerInfo;

[format["You sold %1 for £%2.", (_itemCfg select 5), [_itemValue] call ULP_fnc_numberText]] call ULP_fnc_hint;

_ctrl ctrlEnable true;