/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getName";

_this params [
	["_object", objNull, [objNull]],
	["_checkMask", false, [true]]
];

if (_object isKindOf "Man" && { isPlayer _object }) exitWith {
	if ([goggles _object] call ULP_fnc_isMask || { [headgear _object] call ULP_fnc_isMask }) exitWith { "Masked Player" };
	name _object
};

_object getVariable ["name", ""];