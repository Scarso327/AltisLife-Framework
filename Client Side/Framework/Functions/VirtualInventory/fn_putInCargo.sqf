/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_putInCargo";

if (canSuspend) exitWith {
    [ULP_fnc_putInCargo, _this] call ULP_fnc_directCall;
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

private _containerList = _display displayCtrl 4204;

private _item = _containerList lnbData [(lnbCurSelRow _containerList), 0];
if (_item isEqualTo "") exitWith {
	["You need to selected something to put into this container!"] call ULP_fnc_hint;
};

if (_item in getArray (missionConfigFile >> "CfgVehicles" >> (typeOf _container) >> "blacklistedItems")) exitWith {
	["This item can't be stored in this container..."] call ULP_fnc_hint;
};

private _data = ULP_Inventory getOrDefault [_item, 0];

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
	["You don't have any of this item to put in this container!"] call ULP_fnc_hint;
};

private _maxCarry = floor ((([_container] call ULP_fnc_maxLoad) - ([_container] call ULP_fnc_currentLoad)) / getNumber(missionConfigFile >> "CfgVirtualItems" >> _item >> "weight"));

if (_maxCarry <= 0) exitWith {
	["This vehicle doesn't enough inventory space to fit even one of these items!"] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, (_count min _maxCarry)], [_display, _container, _item, _data],
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

		if ([_container, _item, _value] call ULP_fnc_addToCargo) then {
			if ([_item, _value, true] call ULP_fnc_handleItem) then {
				[format["You have put <t color='#B92DE0'>%1 %2(s)</t> into this container.", _value, _name]] call ULP_fnc_hint;
				[_display, 0] call ULP_fnc_updateInventory;
				[_display, 1] call ULP_fnc_updateInventory;
			} else {
				[_container, _item, _value] call ULP_fnc_removeFromCargo;
				[format["You don't have %1 %2(s) to put in this container!", _value, _name]] call ULP_fnc_hint;
			};
		} else {
			[format["This container doesn't have enough space to take <t color='#B92DE0'>%1 %2(s)</t>!", _value, _name]] call ULP_fnc_hint;
		};
	}, false
] call ULP_fnc_selectNumber;