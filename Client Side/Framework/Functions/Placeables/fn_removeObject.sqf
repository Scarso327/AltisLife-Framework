/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeObject";

if (canSuspend) exitWith {
    [ULP_fnc_removeObject, _this] call ULP_fnc_directCall;
};

_this params [
	["_object", objNull, [objNull]]
];

if !([_object] call ULP_fnc_isPlaceable) exitWith { false };

deleteVehicle _object;
true