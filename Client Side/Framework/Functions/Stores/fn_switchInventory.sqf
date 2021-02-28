/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_switchInventroy";

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _cartList = _display displayCtrl 3107;
private _removeButton = _display displayCtrl 3109;
private _invList = _display displayCtrl 3112;

lbClear _invList;
_invList lbSetCurSel -1;

if (_index isEqualTo 0) then {
	// Cart

	_cartList ctrlShow true;
	_invList ctrlShow false;

	_removeButton ctrlSetEventHandler ["ButtonClick", "[(_this select 0), -1] call ULP_fnc_removeCart"];
	_removeButton ctrlSetStructuredText parseText "<t align = 'center'>Remove From Cart</t>";

} else {
	// Player Inventory
	
	_invList ctrlShow true;
	_cartList ctrlShow false;

	_removeButton ctrlSetEventHandler ["ButtonClick", "_this call ULP_fnc_sellItem"];
	_removeButton ctrlSetStructuredText parseText "<t align = 'center'>Sell Item</t>";

	private _inv = [player] call ULP_fnc_getInventory;

	{
		([_x] call ULP_fnc_itemCfg) params [
			"", "", "", "", "_picture", "_displayName", "_price"
		];

		_price = _price * (getNumber (missionConfigFile >> "CfgStores" >> "sellPerc")); // All items sell for 20% of original value...

		private _item = _invList lbAdd _displayName;
		_invList lbSetTooltip [_item, format["%1: £%2", _displayName, _price]];
		_invList lbSetPicture [_item, _picture];
		_invList lbSetValue [_item, _price];
		_invLIst lbSetData [_item, _x];
	} forEach _inv;
};