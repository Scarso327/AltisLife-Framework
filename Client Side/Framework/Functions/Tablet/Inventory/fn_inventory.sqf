/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_inventory";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];

[(_display displayCtrl 23015), format["%1/%2", _carryWeight, _maxWeight], "right"] call ULP_UI_fnc_setVAlignText;

private _toolbox = _display displayCtrl 23014;

private _list = _display displayCtrl 23016;
lbClear _list;

private _info = _display displayCtrl 23017;

private _useButton = _display displayCtrl 23018;
private _removeButton = _display displayCtrl 23019;

// Privating outside loop is faster...
private _cfgRoot = "CfgVirtualItems";
private _cfg = configNull;
private _item = -1;

switch (lbCurSel _toolbox) do {
	case 1: {
		_cfgRoot = "Licenses";

		_useButton ctrlShow false;
		_removeButton ctrlShow false;

		{
			_cfg = missionConfigFile >> "Licenses" >> _x;

			if (isClass _cfg) then {
				_item = _list lbAdd format ["%1", getText(_cfg >> "displayName")];
				_list lbSetData [_item, _x];
			};
		} forEach ULP_Licenses;
	};
	default {
		private _icon = "";

		_useButton ctrlShow true;
		_removeButton ctrlShow true;

		{
			_cfg = missionConfigFile >> "CfgVirtualItems" >> _x;

			if (isClass _cfg) then {
				_item = _list lbAdd format ["%2 [x%1]", _y, getText(_cfg >> "displayName")];
				_list lbSetData [_item, _x];

				_icon = getText(_cfg >> "icon");

				if !(_icon isEqualTo "") then {
					_list lbSetPicture [_item, _icon];
				};
			};
		} forEach ULP_Inventory;
	};
};

if ((lbSize _list) > 0) then {
	_list lbSetCurSel 0;
} else {
	_list lbAdd "Nothing Found...";
	_info ctrlSetStructuredText parseText "";
};

_display setVariable ["cfg", _cfgRoot];


[_list, 0] call ULP_fnc_invLbChange;