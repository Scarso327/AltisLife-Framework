/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeCart";

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith { systemChat "Cart Ctrl Failure" };

// Update information to list as this was called from button...
if (_index isEqualTo -1) then {
	_ctrl = _display displayCtrl 3107;
	_index = lbCurSel _ctrl;
};

private _itemValue = _ctrl lbValue _index;
_ctrl lbDelete _index;

// Update value...
uiNamespace setVariable ["cartValue", ((uiNamespace getVariable ["cartValue", _itemValue]) - _itemValue)];

private _texList = _display displayCtrl 3106;
[_texList, (lbCurSel _texList)] call ULP_fnc_onTextureSwitch;