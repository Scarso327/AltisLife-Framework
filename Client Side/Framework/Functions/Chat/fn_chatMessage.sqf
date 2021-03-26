/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_chatMessage";

_this params [
	["_message", "", [""]],
	["_params", [], [[]]]
];

private _cfg = missionConfigFile >> "CfgChat" >> "Messages" >> _message;
if !(isClass _cfg || { (count _params) isEqualTo getNumber (_cfg >> "params") }) exitWith { false };

private _msg = [getText (_cfg >> "message")];
_msg append _params;

systemChat format _msg;
true