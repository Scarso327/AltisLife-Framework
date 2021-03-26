/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_escort";

if (canSuspend) exitWith {
    [ULP_fnc_escort, _this] call ULP_fnc_directCall;
};

_this params [
	["_target", cursorObject, [objNull]],
	["_escorter", objNull, [objNull]],
	["_escort", false, [true]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) } || { (_target distance _escorter) >= 3 }) exitWith {};

if (_escort) then {
    if (!([_target] call ULP_fnc_isRestrained) || { [_target] call ULP_fnc_isEscorted }) exitWith {};
    _target attachTo [_escorter, [0.1, 1.1, 0]];

	ULP_Escort = _target;
} else {
    detach _target;
	ULP_Escort = nil;
};