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
	hint "You must be the registered cargo user to take or put items into this container";
};

private _containerList = _display displayCtrl 4204;

private _item = _containerList lnbData [(lnbCurSelRow _containerList), 0];
if (_item isEqualTo "") exitWith {
	hint "You need to selected something to put into this container...";
};

private _count = ULP_Inventory getOrDefault [_item, 0];
if (_count <= 0) exitWith {
	hint "You don't have any of this item to put in this container...";
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

		if ([_container, _item, _value] call ULP_fnc_addToCargo) then {
			if ([_item, _value, true] call ULP_fnc_handleItem) then {
				hint format["You have put %1 %2(s) into this container...", _value, _name];
				[_display, 0] call ULP_fnc_updateInventory;
				[_display, 1] call ULP_fnc_updateInventory;
			} else {
				[_container, _item, _value] call ULP_fnc_removeFromCargo;
				hint format["You don't have %1 %2(s) to put in this container...", _value, _name];
			};
		} else {
			hint format["This container doesn't have enough space to take %1 %2(s)...", _value, _name];
		};
	}, false
] call ULP_fnc_selectNumber;