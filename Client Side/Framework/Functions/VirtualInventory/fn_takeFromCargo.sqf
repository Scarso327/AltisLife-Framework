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
	hint "You must be the registered cargo user to take or put items into this container";
};

private _containerList = _display displayCtrl 4208;

private _item = _containerList lnbData [(lnbCurSelRow _containerList), 0];
if (_item isEqualTo "") exitWith {
	hint "You need to selected something to take from this container...";
};

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];
private _count = _cargo getOrDefault [_item, 0];
if (_count <= 0) exitWith {
	hint "You can't take this item from the container as it doesn't contain this item...";
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _count], [_display, _container, _item],
	{
		_this params [
			["_display", displayNull, [displayNull]],
			["_container", objNull, [objNull]],
			["_item", "", [""]],
			"",
			["_value", 1, [0]]
		];

		if (isNull _display || { _item isEqualTo "" }) exitWith {};

		private _name = getText (missionConfigFile >> "CfgVirtualItems" >> _item >> "displayName");

		if ([_item, _value] call ULP_fnc_handleItem) then {
			if ([_container, _item, _value] call ULP_fnc_removeFromCargo) then {
				hint format["You have taken %1 %2(s) from this container...", _value, _name];
				[_display, 0] call ULP_fnc_updateInventory;
				[_display, 1] call ULP_fnc_updateInventory;
			} else {
				[_item, _value, true] call ULP_fnc_handleItem;
				hint format["This container doesn't contain %1 %2(s) to take...", _value, _name];
			};
		} else {
			hint format["You don't have enough inventory space to take %1 %2(s)...", _value, _name];
		};
	}, false
] call ULP_fnc_selectNumber;