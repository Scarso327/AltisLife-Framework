/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_saveCart";

private _display = _this param [0, displayNull, [displayNull]];
private _name = _this param [1, _display getVariable ["saved_cart", ""], [""]];

if (isNull _display || { _name isEqualTo "" }  || { isNil "_name" }) exitWith { systemChat "Error occured while saving cart"; };

private _storeCfgName = format["%1%2", configName (_display getVariable "storeCfg"), configName (_display getVariable "curStore")];
private _allSavedCarts = + (profileNamespace getVariable ["ULP_SavedCarts", createHashMap]);
private _savedCarts = _allSavedCarts getOrDefault [_storeCfgName, createHashMap];

private _maxCarts = getNumber (missionConfigFile >> "CfgStores" >> "maxCarts");
if ([] call ULP_fnc_donatorLevel > 0) then {
	_maxCarts = _maxCarts + getNumber (missionConfigFile >> "CfgStores" >> "extraDonatorCarts");
};

if ((count _savedCarts) >= _maxCarts) exitWith {
	[format["You've already saved your max of %1!", _maxCarts]] call ULP_fnc_hint;
};

private _cartList = _display displayCtrl 3107;
private _cartSize = lbSize _cartList;
if (_cartSize isEqualTo 0) exitWith {
	["You must add something to your cart before you can save it!"] call ULP_fnc_hint;
};

private _savedCart = [];

for "_i" from 0 to (_cartSize - 1) do {
	_savedCart pushBack (parseSimpleArray (_cartList lbData _i));
};

if (_savedCart isEqualTo []) exitWith {}; // Failsafe

_savedCarts set [_name, _savedCart];
_allSavedCarts set [_storeCfgName, _savedCarts];

profileNamespace setVariable ["ULP_SavedCarts", _allSavedCarts];
saveProfileNamespace;

_display setVariable ["saved_cart", _name];
(_display displayCtrl 3117) ctrlEnable true;
(_display displayCtrl 3118) ctrlEnable true;

[format ["Cart '%1' has been saved", _name]] call ULP_fnc_hint;