/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onConflictEnded";

_this params [
	["_group", grpNull, [grpNull]],
	["_score", 0, [0]]
];

if (!hasInterface || { !([["NotifyConflict", "Notifications"] call ULP_fnc_getOption] call ULP_fnc_bool) }) exitWith {};

if (isNull _group) exitWith {
	["<t color='#ff0000' size='1.5px'>Conflict<br/></t><t color='#ffffff' size='1px'>The conflict ended with no winners"] call ULP_fnc_hint;
};

[format ["<t color='#ff0000' size='1.5px'>Conflict<br/></t><t color='#ffffff' size='1px'>%1 won the conflict with <t color='#B92DE0'>%2</t> points", groupId _group, _score]] call ULP_fnc_hint;