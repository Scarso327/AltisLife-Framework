/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeToCargo";

if (canSuspend) exitWith {
    [ULP_fnc_removeToCargo, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]],
	["_item", "", [""]],
	["_data", 1, [0, [], ""]],
	["_global", true, [false]]
];

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _container || { !(isClass _vItem) } || { !([_container] call ULP_fnc_hasInventory) }) exitWith { false };

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

if !(_item in _cargo) exitWith { false };

private _count = switch (typeName _data) do {
	case "STRING": { 1 };
	case "ARRAY": { count _data };
	default { _data };
};

if ([getNumber (_vItem >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
	private _current = _cargo getOrDefault [_item, []];
	_count = 0 max ((count _current) - _count);

	if (_count <= 0) then {
		_cargo deleteAt _item;
	} else {

		if (_data isEqualType "") then {
			_current deleteAt (_current find _data);
		} else {
			_current = _current - _data;
		};

		_cargo set [_item, _current];
	};
} else {
	_count = 0 max ((_cargo getOrDefault [_item, 0]) - _count);

	if (_count <= 0) then {
		_cargo deleteAt _item;
	} else {
		_cargo set [_item, _count];
	};
};

if ((count _cargo) isEqualTo 0 && { isNumber (missionConfigFile >> "CfgVehicles" >> (typeOf _container) >> "tempStorage") }) then {
	deleteVehicle _container;
} else {
	_container setVariable ["ULP_VirtualCargo", _cargo, _global];
};
true