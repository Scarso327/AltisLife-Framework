/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_loadSavedCart";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _storeCfg = _display getVariable "curStore";
private _storeCfgName = format["%1%2", configName (_display getVariable "storeCfg"), configName _storeCfg];

private _allSavedCarts = + (profileNamespace getVariable ["ULP_SavedCarts", createHashMap]);
private _savedCarts = _allSavedCarts getOrDefault [_storeCfgName, createHashMap];

private _selectableCarts = (keys _savedCarts) apply { ["", _x, _x, -1] };
if (_selectableCarts isEqualTo []) exitWith {
	["You have no saved carts"] call ULP_fnc_hint;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), _selectableCarts, 
	["Select", "Cancel"], [_savedCarts, _storeCfg, _display], {
	_this params [
		["_savedCarts", createHashMap, [createHashMap]],
		["_storeCfg", configNull, [configNull]],
		["_storeDisplay", displayNull, [displayNull]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display || { isNull _storeDisplay }) exitWith {};
	private _list = _display displayCtrl 4509;

	private _index = lbCurSel _list;
	if (_index isEqualTo -1) exitWith { ["You didn't select a cart to load"] call ULP_fnc_hint; };

	private _selectedCartName = _list lbData _index;
	if (isNil "_selectedCartName" || { _selectedCartName isEqualTo "" }) exitWith {};

	private _cartToLoad = _savedCarts getOrDefault [_selectedCartName, []];
	if (_cartToLoad isEqualTo []) exitWith {};

	private _cartList = _storeDisplay displayCtrl 3107;
	lbClear _cartList;

	private _textList = _storeDisplay displayCtrl 3106;

	// Load cart here

	private _cartValue = 0;
	private _storeItemCfg = getText((_storeDisplay getVariable "storeCfg") >> "itemCfg");

	{
		scopeName "fn_loadSavedCart_loadLoop";

		_x params [ "_className", "_texture", "_categoryCfgName" ];

		private _cfg = _storeCfg >> _categoryCfgName >> _className;

		if (!isClass _cfg || { isText (_cfg >> "condition") && { !(call compile getText (_cfg >> "condition")) } }) exitWith {};

		private _itemCfg = [(configName _cfg)] call ULP_fnc_itemCfg;

		private _displayName = ([
			(_itemCfg select 5),
			getText (_cfg >> "displayName")
		] select (isText (_cfg >> "displayName")));

		private _picture = ([
			(_itemCfg select 4),
			getText (_cfg >> "picture")
		] select (isText (_cfg >> "picture")));

		private _textureName = "Default";

		private _textures = ([
			((_itemCfg select 7) apply { configName _x }), 
			((_cfg >> "Textures") call BIS_fnc_getCfgSubClasses)
		] select (isClass (_cfg >> "Textures")));

		if !(_textures isEqualTo []) then {
			if !(_texture in _textures) exitWith { breakOut "fn_loadSavedCart_loadLoop"; };

			_textureName = getText(missionConfigFile >> _storeItemCfg >> _className >> "Textures" >> _texture >> "displayName");
		};

		private _name = format["%1 (%2)", _displayName, _textureName];

		private _itemValue = _itemCfg select 6;
		_cartValue = _cartValue + _itemValue;

		private _item = _cartList lbAdd _name;
		_cartList lbSetTooltip [_item, _name];
		_cartList lbSetPicture [_item, _picture];
		_cartList lbSetValue [_item, _itemValue];
		_cartList lbSetData [_item, (str [_className, _texture, _categoryCfgName])];
	} forEach _cartToLoad;

	_storeDisplay setVariable ["cartValue", _cartValue];

	private _selectedTexture = lbCurSel _textList;
	
	if !(_selectedTexture isEqualTo -1) then {
		[_textList, _selectedTexture] call ULP_fnc_onTextureSwitch;
	};

	_storeDisplay setVariable ["saved_cart", _selectedCartName];

	(_storeDisplay displayCtrl 3115) ctrlEnable true;
	(_storeDisplay displayCtrl 3117) ctrlEnable true;
	(_storeDisplay displayCtrl 3118) ctrlEnable true;

	[format ["Loaded Cart '%1'", _selectedCartName]] call ULP_fnc_hint;
}, false] call ULP_fnc_selectObject;