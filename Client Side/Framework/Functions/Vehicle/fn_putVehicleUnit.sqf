/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_putVehicleUnit";

_this params [
	["_vehicle", objNull, [objNull]],
	["_unit", objNull, [objNull]]
];

if (isNull _vehicle || { isNull _unit } || { (vehicle _unit) isEqualTo _vehicle }) exitWith { false };

// We've been put into the vehicle while restraiend so need to make sure we know we're supposed to be here
if ([_unit] call ULP_fnc_isRestrained && { !((_unit getVariable ["restrained_in_vehicle", objNull]) isEqualTo _vehicle) }) then {
	_unit setVariable ["restrained_in_vehicle", _vehicle, true];
};

_unit moveInCargo _vehicle;
true