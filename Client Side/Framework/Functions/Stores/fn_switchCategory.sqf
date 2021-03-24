/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_switchCategory";

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
private _storeCfg = _display getVariable ["curStore", configNull];

if (!(isClass (_storeCfg)) || { isNull _display }) exitWith { systemChat "Category Failure" };

private _itemList = _display displayCtrl 3103;
lbClear _itemList;
_itemList lbSetCurSel -1;

// Wipe item specific information...
private _textList = _display displayCtrl 3106;
lbClear _textList;
_textList lbSetCurSel -1;

(_display displayCtrl 3104) ctrlSetText "";
(_display displayCtrl 3105) ctrlSetStructuredText parseText ([] call ULP_fnc_cartInfo);

private _items = ("isClass _x" configClasses (_storeCfg >> ((_storeCfg call BIS_fnc_getCfgSubClasses) select _index)));

if ((count _items) isEqualTo 0) exitWith {
	_itemList lbAdd "No Items";

	// TODO : Disable Buy...
};

{
	private _itemCfg = [(configName _x)] call ULP_fnc_itemCfg;
	private _itemInfo = [
		(configName _x),
		([
			(_itemCfg select 5),
			getText (_x >> "displayName")
		] select (isText (_x >> "displayName"))),
		([
			(_itemCfg select 4),
			getText (_x >> "picture")
		] select (isText (_x >> "picture"))),
		([
			((_itemCfg select 7) apply { configName _x }), 
			((_x >> "Textures") call BIS_fnc_getCfgSubClasses)
		] select (isClass (_x >> "Textures"))),
		isNumber(_x >> "allowDefaultTexture")
	];

	private _item = _itemList lbAdd (_itemInfo select 1);
	
	_itemList lbSetTooltip [_item, (_itemInfo select 1)];
	_itemList lbSetPicture [_item, (_itemInfo select 2)];
	_itemList lbSetValue [_item, (_itemCfg select 6)];
	_itemList lbSetData [_item, (str _itemInfo)];
} forEach (_items select {
	!isText (_x >> "condition") || { call compile getText (_x >> "condition") }
});