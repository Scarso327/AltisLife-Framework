/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addCart";

_this params [
	["_idd", 3100, [0]],
	["_itemIdc", 3103, [0]],
	["_textIdc", 3106, [0]],
	["_cartIdc", 3107, [0]]
];

private _display = findDisplay _idd;

if (isNull _display) exitWith { systemChat "Cart Failure" };

private _itemList = _display displayCtrl _itemIdc;
private _cartList = _display displayCtrl _cartIdc;
private _textList = _display displayCtrl _textIdc;
if (isNull _itemList || { isNull _cartList } || { isNull _textList }) exitWith { systemChat "Cart Ctrl Failure" };

private _curItem = lbCurSel _itemList;

if (_curItem isEqualTo -1) exitWith {
	hint "You must select an item to add to your cart...";
};

private _data = _itemList lbData _curItem;
if (_data isEqualTo "") exitWith {};
_data = parseSimpleArray _data;

_data params [
	"_className", "_displayName", "_picture"
];

private _texSel = lbCurSel _textList;
private _texData = _textList lbData _texSel;
_texData = parseSimpleArray _texData;

_texData params [
	"_texClass", "_texName", "_texPic"
];

if !(_texPic isEqualTo "") then {
	_picture = _texPic;
};

private _itemValue = (_itemList lbValue _curItem) + (_textList lbValue _texSel);

private _name = format["%1 (%2)", _displayName, _texName];
private _item = _cartList lbAdd _name;
_cartList lbSetTooltip [_item, _name];
_cartList lbSetPicture [_item, _picture];
_cartList lbSetValue [_item, _itemValue];
_cartList lbSetData [_item, (str [_className, _texClass])];

uiNamespace setVariable ["cartValue", ((uiNamespace getVariable ["cartValue", 0]) + _itemValue)];
[_textList, _texSel] call ULP_fnc_onTextureSwitch;