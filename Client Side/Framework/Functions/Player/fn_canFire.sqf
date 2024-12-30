/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canFire";

_this params [
	["_target", player, [objNull]]
];

!([_target] call ULP_fnc_isKnocked 
	&& { [_target] call ULP_fnc_isRestrained }
	&& { [_target] call ULP_fnc_isSurrendered }
	&& { isDowned(_target) })