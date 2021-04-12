/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canHeal";

_this params [
	["_target", player, [objNull]]
];

(!(isNull _target) && { alive _target } && { !(isDowned(_target)) } && {
	((["FirstAidKit"] call ULP_fnc_hasItem) > 0 && ((damage _target) > 0.25)) || ((["MediKit"] call ULP_fnc_hasItem) > 0 && ((damage _target) > 0.01))
})