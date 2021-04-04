/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_market";

_display = _this;
if (isNull _display) exitWith {};

private _filter = _display displayCtrl 23032;
private _list = _display displayCtrl 23033;
lnbClear _list;

[_filter, _list] call BIS_fnc_initListNBoxSorting;

{
	private _itemIcon = getText (_x >> "icon");
	private _weight = getNumber (_x >> "weight");
	private _illegal = [getNumber (_x >> "Settings" >> "isIllegal")] call ULP_fnc_bool;
	private _sellPrice = getNumber (_x >> "sellPrice");

	([_buyPrice, _sellPrice, !_illegal] call ULP_fnc_getSellPrices) params [
		["_sellPrice", _sellPrice, [0]]
	];

	private _row = _list lnbAddRow [
		getText (_x >> "displayName"), 
		[_weight] call ULP_fnc_numberText,
		"",
		([format["£%1", [_sellPrice] call ULP_fnc_numberText], "-"] select (_sellPrice isEqualTo -1))
	];

	if !(_itemIcon isEqualTo "") then {
		_list lnbSetPicture [[_row, 0], _itemIcon];
	};

	_list lnbSetData [[_row, 0], configName _x];
	_list lnbSetValue[[_row, 1], _weight];
	_list lnbSetValue[[_row, 2], parseNumber _illegal];
	_list lnbSetPicture [[_row, 2], format["\a3\3DEN\Data\Controls\ctrlCheckbox\%1_ca.paa", (["textureChecked", "textureUnchecked"] select (_illegal))]];
	_list lnbSetValue[[_row, 3], _sellPrice];
} forEach ("getNumber (_x >> ""Settings"" >> ""onMarket"") isEqualTo 1" configClasses (missionConfigFile >> "CfgVirtualItems"));