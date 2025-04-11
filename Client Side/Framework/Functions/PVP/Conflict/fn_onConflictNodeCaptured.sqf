/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onConflictNodeCaptured";

if !(hasInterface) exitWith {};

_this params [
	["_zone", objNull, [objNull]],
	["_group", grpNull, [grpNull]]
];

private _nodeCfg = _zone getVariable ["nodeCfg", configNull];
if (isNull _nodeCfg || { isNull _group } || { !([["NotifyConflict", "Notifications"] call ULP_fnc_getOption] call ULP_fnc_bool) }) exitWith {};

[format ["<t color='#ff0000' size='1.5px'>Conflict<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> has been captured by <t color='#B92DE0'>%2</t>",
	getText (_nodeCfg >> "displayName"), [_group] call ULP_fnc_getGroupName]] call ULP_fnc_hint;