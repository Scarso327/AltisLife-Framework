/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_updateInventory";

if (canSuspend) exitWith {
    [ULP_fnc_updateInventory, _this] call ULP_fnc_directCall;
};

_this params [
	["_display", displayNull, [displayNull]],
	["_type", 0, [0]]
];

if (isNull _display) exitWith { false };

private _container = _display getVariable ["container", objNull];
if (isNull _container) exitWith { false };

private _addItem = {
	_this params [ "_list", "_searchValue", "_x", "_y" ];

	private _cfg = missionConfigFile >> "CfgVirtualItems" >> _x;

	if (isClass _cfg) then {
		private _itemIcon = getText (_cfg >> "icon");

		if ([getNumber (_cfg >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
			{
				private _displayName = format [getText (_cfg >> "displayName"), _x];

				if (((toLower _displayName) find _searchValue) > -1) then {
					private _row = _list lnbAddRow [_displayName, "-"];

					if !(_itemIcon isEqualTo "") then {
						_list lnbSetPicture [[_row, 0], _itemIcon];
					};

					_list lnbSetData [[_row, 0], configName _cfg];
					_list lnbSetData [[_row, 1], (if (_x isEqualType 0) then { str _x } else { _x })];
				};
			} forEach _y;
		} else {
			private _displayName = getText (_cfg >> "displayName");

			if (((toLower _displayName) find _searchValue) > -1) then {
				private _row = _list lnbAddRow [
					getText (_cfg >> "displayName"), 
					[_y] call ULP_fnc_numberText
				];

				if !(_itemIcon isEqualTo "") then {
					_list lnbSetPicture [[_row, 0], _itemIcon];
				};

				_list lnbSetData [[_row, 0], _x];
				_list lnbSetValue [[_row, 1], _y];
			};
		};
	};
};

if (_type isEqualTo 0) then {
	ULP_CarryInfo params ["_carryWeight", "_maxWeight"];

	private _personalTitle = _display displayCtrl 4202;
	_personalTitle ctrlSetStructuredText parseText format["Personal Inventory<t align='right'>%1/%2</t>", _carryWeight, _maxWeight];

	private _list = _display displayCtrl 4204;
	lnbClear _list;

	private _searchValue = toLower (ctrlText (_display displayCtrl 4210));

	{
		[_list, _searchValue, _x, _y] call _addItem;
	} forEach ULP_Inventory;

	(_display displayCtrl 4205) ctrlEnable (((lbSize _list) > 0) && { [_container] call ULP_fnc_isCargoUser });
} else {
	private _containerTitle = _display displayCtrl 4206;
	_containerTitle ctrlSetStructuredText parseText format["Container Inventory<t align='right'>%1/%2</t>", [_container] call ULP_fnc_currentLoad, [_container] call ULP_fnc_maxLoad];

	private _list = _display displayCtrl 4208;
	lnbClear _list;

	private _searchValue = toLower (ctrlText (_display displayCtrl 4211));

	private _inventory = _container getVariable ["ULP_VirtualCargo", createHashMap];
	_display setVariable ["lastInventory", _inventory];

	{
		[_list, _searchValue, _x, _y] call _addItem;
	} forEach _inventory;

	(_display displayCtrl 4209) ctrlEnable (((lbSize _list) > 0) && { [_container] call ULP_fnc_isCargoUser });
};

true