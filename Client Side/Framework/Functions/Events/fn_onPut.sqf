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

[] call ULP_fnc_maxCarry;