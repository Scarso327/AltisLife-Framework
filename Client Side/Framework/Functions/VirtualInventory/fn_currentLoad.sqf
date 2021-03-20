/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_currentLoad";

if (canSuspend) exitWith {
    [ULP_fnc_currentLoad, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]]
];

private _cargo = _container getVariable ["ULP_VirtualCargo", createHashMap];
private _load = 0;

{
    _load = _load + (getNumber (missionConfigFile >> "CfgVirtualItems" >> _x >> "weight")) * _y;
} forEach _cargo;

_load