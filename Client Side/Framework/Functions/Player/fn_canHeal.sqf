/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canHeal";

_this params [
	["_target", player, [objNull]]
];

(!(isNull _target) 
	&& { isPlayer _target } 
	&& { alive _target } 
	&& { !(isDowned(_target)) } 
	&& { isNull (objectParent _target) } 
	&& { _target isKindOf "Man" }
	// The target is us or do the checks again but for us
	&& { (_target isEqualTo player) || {
		alive player 
		&& { !(isDowned(player)) } 
		&& { isNull (objectParent player) } 
		&& { (player distance _target) <= 3 } 
	} }
	&& {
	((["FirstAidKit"] call ULP_fnc_hasItem) > 0 && { ((damage _target) > 0.25) }) || ((["MediKit"] call ULP_fnc_hasItem) > 0 && { ((damage _target) >= 0.01) })
})