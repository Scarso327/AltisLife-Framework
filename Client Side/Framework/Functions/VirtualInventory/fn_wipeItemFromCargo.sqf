/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_wipeItemFromCargo";

if (canSuspend) exitWith {
    [ULP_fnc_wipeItemFromCargo, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]],
	["_item", "", [""]]
];

private _vItem = missionConfigFile >> "CfgVirtualItems" >> _item;
if (isNull _container || { !(isClass _vItem) } || { !([_container] call ULP_fnc_hasInventory) }) exitWith { 0 };

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];

if !(_item in _cargo) exitWith { 0 };

private _count = _cargo getOrDefault [_item, 0];

if ([getNumber (_vItem >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
	_count = count (_cargo getOrDefault [_item, []]);
};

_cargo deleteAt _item;
_count