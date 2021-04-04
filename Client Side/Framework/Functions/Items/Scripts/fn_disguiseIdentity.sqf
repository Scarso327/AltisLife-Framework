/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_disguiseIdentity";

_this params [
	["_item", "", [""]],
	["_identity", name player, [""]]
];

// Stop spam...
if (time < (player getVariable ["last_disguised", 0])) exitWith {
	hint "You've disguised yourself recently, please wait...";
	false
};
player setVariable ["last_disguised", time + 3];

if (_identity isEqualTo (name player) || { ((player getVariable ["name", name player]) isEqualTo _identity) }) then {
	player setVariable ["name", nil, true];
	hint "You've returned your public identity to normal...";
} else {
	player setVariable ["name", _identity, true];
	hint format ["You've changed your public identity to %1", _identity];
};

true