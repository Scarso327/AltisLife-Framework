/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addToCargo";

if (canSuspend) exitWith {
    [ULP_fnc_addToCargo, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]],
	["_item", "", [""]],
	["_data", 1, [0, [], ""]],
	["_global", true, [false]],
	["_ignoreLoad", false, [true]]
];

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _container || { !(isClass _vItem) } || { !([_container] call ULP_fnc_hasInventory) }) exitWith { false };

private _containerCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _container);
private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

private _count = switch (typeName _data) do {
	case "STRING": { 1 };
	case "ARRAY": { count _data };
	default { _data };
};

if ((([_container] call ULP_fnc_currentLoad) + (getNumber (_vItem >> "weight") * _count)) > ([_container] call ULP_fnc_maxLoad) && { !_ignoreLoad }) exitWith { false };

if ([getNumber (_vItem >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
	private _current = _cargo getOrDefault [_item, []];

	if (_data isEqualType "") then {
		_current pushBack _data;
	} else {
		_current append _data;
	};

	_cargo set [_item, _current];
} else {
	_count = (_cargo getOrDefault [_item, 0]) + _count;
	_cargo set [_item, _count];
};

_container setVariable ["ULP_VirtualCargo", _cargo, _global];
true