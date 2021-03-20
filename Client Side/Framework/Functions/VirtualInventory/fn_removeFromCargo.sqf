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
	["_count", 1, [0]],
	["_global", true, [false]]
];

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _container || { !(isClass _vItem) } || { !([_container] call ULP_fnc_hasInventory) }) exitWith { false };

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

if !(_item in _cargo) exitWith { false };
_count = 0 max ((_cargo getOrDefault [_item, 0]) - _count);

if (_count <= 0) then {
	_cargo deleteAt _item;
} else {
	_cargo set [_item, _count];
};

_container setVariable ["ULP_VirtualCargo", _cargo, _global];
true