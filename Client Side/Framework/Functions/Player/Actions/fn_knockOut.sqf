/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_knockOut";

_this params [
	["_target", cursorObject, [objNull]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) } || { _target isEqualTo player }|| { (_target distance player) >= 3 } || { isDowned(_target) } || { isDowned(player) }) exitWith {};

[player] remoteExecCall ["ULP_fnc_onKnocked", _target];