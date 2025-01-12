/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPut";

_this params [
	["_unit", objNull, [objNull]],
    ["_container", objNull, [objNull]],
    ["_item", "", [""]]
];

if (isNull _unit || { _item isEqualTo "" }) exitWith { true };

// Delay to ensure the time sets properly
[1, [], { [] call ULP_fnc_maxCarry; }] call ULP_fnc_waitExecute;