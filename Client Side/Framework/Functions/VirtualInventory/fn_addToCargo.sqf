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
	["_count", 1, [0]],
	["_global", true, [false]],
	["_ignoreLoad", false, [true]]
];

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _container || { !(isClass _vItem) } || { !([_container] call ULP_fnc_hasInventory) }) exitWith { false };

private _containerCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _container);
private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

if ((([_container] call ULP_fnc_currentLoad) + (getNumber (_vItem >> "weight") * _count)) > ([_container] call ULP_fnc_maxLoad) && { !_ignoreLoad }) exitWith { false };

_count = (_cargo getOrDefault [_item, 0]) + _count;
_cargo set [_item, _count];

_container setVariable ["ULP_VirtualCargo", _cargo, _global];
true