/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_restrainTarget";

_this params [
	["_target", cursorObject, [objNull]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) }|| { (_target distance player) >= 3 } || { [_target] call ULP_fnc_isRestrained }) exitWith {};

[player] remoteExecCall ["ULP_fnc_onRestrained", _target];