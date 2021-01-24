/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_toggleRestraint";

_this params [
	["_target", cursorObject, [objNull]],
	["_restrain", true, [false]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) }|| { (_target distance player) >= 3 }) exitWith {};

if (_restrain) then {
	if ([_target] call ULP_fnc_isRestrained) then {
		[player] remoteExecCall ["ULP_fnc_onRestrained", _target];
	};
} else {
	if !([_target] call ULP_fnc_isRestrained) then {
		[player] remoteExecCall ["ULP_fnc_onUnrestrained", _target];
	};
};