/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_takeFromCargo";

if (canSuspend) exitWith {
    [ULP_fnc_takeFromCargo, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _container = _display getVariable ["container", objNull];
if (isNull _container || { !([_container] call ULP_fnc_isCargoUser) }) exitWith {
	_ctrl ctrlEnable false;
	["You must be the registered cargo user to take or put items into this container!"] call ULP_fnc_hint;
};

private _containerList = _display displayCtrl 4208;

private _item = _containerList lnbData [(lnbCurSelRow _containerList), 0];
if (_item isEqualTo "") exitWith {
	["You need to selected something to take from this container!"] call ULP_fnc_hint;
};

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;

// System items are added / removed via script from vehicles
if ([getNumber (_vItem >> "Settings" >> "isSystemItem")] call ULP_fnc_bool) exitWith {
	["This item can't be manually moved from this container"] call ULP_fnc_hint;
};

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

private _data = _cargo getOrDefault [_item, 0];

private _count = _data;

if (_count isEqualType []) then {
	_count = 1;

	private _index = _data find (_containerList lnbData [(lnbCurSelRow _containerList), 1]);

	if (_index < 0) then {
		_count = 0;
	} else {
		_data = _data select _index;
	};
} else {
	_data = -1;
};

if (_count <= 0) exitWith {
	["You can't take this item from the container as it doesn't contain this item!"] call ULP_fnc_hint;
};

ULP_CarryInfo params ["_carryWeight", "_maxWeight"];
private _itemWeight = getNumber(_vItem >> "weight");
private _maxCarry = _count;

if (_itemWeight > 0) then {
	_maxCarry = floor ((_maxWeight - _carryWeight) / _itemWeight);
};

if (_maxCarry <= 0) exitWith {
	["You don't have enough inventory space to fit even one of these items!"] call ULP_fnc_hint;
};

private _maxValue = _count min _maxCarry;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _maxValue], [_display, _container, _item, _data],
	{
		_this params [
			["_display", displayNull, [displayNull]],
			["_container", objNull, [objNull]],
			["_item", "", [""]],
			["_data", 1, [0, "", []]],
			"",
			["_value", 1, [0]]
		];

		if (isNull _display || { _item isEqualTo "" }) exitWith {};

		private _name = getText (missionConfigFile >> "CfgVirtualItems" >> _item >> "displayName");
		if ([getNumber (missionConfigFile >> "CfgVirtualItems" >> _item >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
			_value = _data;
			_name = format [_name, _value];
		};

		if ([_item, _value] call ULP_fnc_handleItem) then {
			if ([_container, _item, _value] call ULP_fnc_removeFromCargo) then {
				[format["You have taken <t color='#B92DE0'>%1 %2(s)</t> from this container!", _value, _name]] call ULP_fnc_hint;
				[_display, 0] call ULP_fnc_updateInventory;
				[_display, 1] call ULP_fnc_updateInventory;
			} else {
				[_item, _value, true] call ULP_fnc_handleItem;
				[format["This container doesn't contain <t color='#B92DE0'>%1 %2(s)</t> to take!", _value, _name]] call ULP_fnc_hint;
			};
		} else {
			[format["You don't have enough inventory space to take <t color='#B92DE0'>%1 %2(s)</t>!", _value, _name]] call ULP_fnc_hint;
		};
	}, false
] call ULP_fnc_selectNumber;