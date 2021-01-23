/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onItemClick";

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
private _storeCfg = uiNamespace getVariable ["curStore", configNull];

if (!(isClass (_storeCfg)) || { isNull _display }) exitWith { systemChat "Item Failure" };

private _data = _ctrl lbData _index;
if (_data isEqualTo "") exitWith {};
_data = parseSimpleArray _data;

_data params [
	"_className", "_displayName", "_picture", "_textures", "_allowDefault"
];

uiNamespace setVariable ["itemData", [_displayName, (_ctrl lbValue _index)]];

(_display displayCtrl 3104) ctrlSetText _picture;

private _storeItemCfg = getText((uiNamespace getVariable "storeCfg") >> "itemCfg");

_textures = (_textures select {
	isClass (missionConfigFile >> _storeItemCfg >> _className >> "Textures" >> _x) && 
	{ call compile (getText (missionConfigFile >> _storeItemCfg >> _className >> "Textures" >> _x >> "condition")) }
}) apply {
	missionConfigFile >> _storeItemCfg >> _className >> "Textures" >> _x
};

private _textList = _display displayCtrl 3106;
lbClear _textList;

if ((count _textures) isEqualTo 0 || { _allowDefault }) then {
	private _item = _textList lbAdd "Default";
	_textList lbSetData [_item, (str ["", "Default"])];
	_textList lbSetValue [_item, 0];
};

{
	private _displayName = getText(_x >> "displayName");
	private _picture = "";

	// Store specific code...
	if (_storeItemCfg isEqualTo "CfgItems") then {
		_picture = ([(configName _x)] call ULP_fnc_itemCfg select 4);
	};

	private _item = _textList lbAdd _displayName;
	_textList lbSetData [_item, (str [(configName _x), _displayName, _picture])];
	_textList lbSetValue [_item, ([0, getNumber(_x >> "price")] select (isNumber (_x >> "price")))];
} forEach _textures;

if !((lbCurSel _textList) isEqualTo 0) then {
	_textList lbSetCurSel 0;
};

[_textList, 0] call ULP_fnc_onTextureSwitch;