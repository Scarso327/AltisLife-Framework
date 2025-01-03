/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_ejectVehicleUnit";

_this params [
	["_unit", objNull, [objNull]]
];

private _vehicle = vehicle _unit;

if (_unit isEqualTo _vehicle) exitWith { false };

if ([_unit] call ULP_fnc_isRestrained && { !(isNull (_unit getVariable ["restrained_in_vehicle", objNull])) }) then {
	_unit setVariable ["restrained_in_vehicle", nil, true];
};

unassignVehicle _unit;
moveOut _unit;
true