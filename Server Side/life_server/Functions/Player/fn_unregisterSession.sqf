/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_unregisterSession";

_this params [
	["_unit", objNull, [objNull]]
];

private _uid = getPlayerUID _unit;

private _session = _unit getVariable "session";
if (isNil "_session" || { !((_session getOrDefault ["SteamID", ""]) isEqualTo _uid) }) exitWith {};

_unit setVariable ["session", nil];