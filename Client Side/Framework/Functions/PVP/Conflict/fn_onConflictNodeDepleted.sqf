/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onConflictNodeDepleted";

if !(hasInterface) exitWith {};

_this params [
	["_previousZone", configNull, [configNull]],
	["_newZone", configNull, [configNull]]
];

if (isNull _previousZone || { !([["NotifyConflict", "PVP"] call ULP_fnc_getOption] call ULP_fnc_bool) }) exitWith {};

if (isNull _newZone) exitWith {
	[format ["<t color='#ff0000' size='1.5px'>Conflict<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> has been fully depleted", getText (_previousZone >> "displayName")]] call ULP_fnc_hint;
};

[format ["<t color='#ff0000' size='1.5px'>Conflict<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> has been fully depleted<br/><t color='#B92DE0'>%2</t> has spawned in it's place",
	getText (_previousZone >> "displayName"), getText (_newZone >> "displayName")]] call ULP_fnc_hint;