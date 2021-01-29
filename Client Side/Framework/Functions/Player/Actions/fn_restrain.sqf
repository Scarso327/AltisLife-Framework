/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_restrain";

_this params [
	["_target", cursorObject, [objNull]],
	["_restrain", true, [false]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) } || { (_target distance player) >= 3 }) exitWith {};

[
	([player, objNull] select ([_target] call ULP_fnc_isRestrained))
] remoteExecCall ["ULP_fnc_onRestrain", _target];