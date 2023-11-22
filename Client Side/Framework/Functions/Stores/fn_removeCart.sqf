/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeCart";

_this params [
	"_ctrl", ["_index", -1, [0]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith { systemChat "Cart Ctrl Failure" };

// Update information to list as this was called from button...
if (_index isEqualTo -1) then {
	_ctrl = _display displayCtrl 3107;
	_index = lbCurSel _ctrl;
};

if (_index isEqualTo -1) exitWith { ["You must select an item to remove from the cart"] call ULP_fnc_hint; };

private _itemValue = _ctrl lbValue _index;
_ctrl lbDelete _index;

// Update value...
_display setVariable ["cartValue", ((_display getVariable ["cartValue", _itemValue]) - _itemValue)];

if ((lbSize (_display displayCtrl 3107)) isEqualTo 0) then {
	(_display displayCtrl 3115) ctrlEnable false;
	(_display displayCtrl 3117) ctrlEnable false;
	(_display displayCtrl 3118) ctrlEnable false;
};

private _texList = _display displayCtrl 3106;
[_texList, (lbCurSel _texList)] call ULP_fnc_onTextureSwitch;