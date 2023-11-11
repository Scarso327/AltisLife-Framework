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

// No active identity and this identity card is our name
if (isNil { player getVariable "name" } && (name player) isEqualTo _identity) exitWith {};

// Stop spam...
if (time < (player getVariable ["last_disguised", 0])) exitWith {
	["You've disguised yourself recently, please wait..."] call ULP_fnc_hint;
	false
};
player setVariable ["last_disguised", time + 3];

if (_identity isEqualTo (name player) || { ((player getVariable ["name", name player]) isEqualTo _identity) }) then {
	player setVariable ["name", nil, true];
	["You've returned your public identity to normal."] call ULP_fnc_hint;
} else {
	player setVariable ["name", _identity, true];
	[format ["You've changed your public identity to <t color='#B92DE0'>%1</t>.", _identity]] call ULP_fnc_hint;
};

true