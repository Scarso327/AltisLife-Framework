/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_sendMessage";

_this params [
	["_type", configNull, [configNull]],
	["_message", "", [""]],
	["_targets", "", ["", objNull]]
];

if (isNull _type || 
	{ _message isEqualTo "" } || 
	{ _targets isEqualType "" && { _targets isEqualTo "" } } || 
	{ _targets isEqualType objNull && { isNull _targets } }
) exitWith { false };

if (_targets isEqualType "") then {
	_targets = call compile _targets;
};

hint format ["Message Sent"];
[_type, _message, [format[getText (_type >> "sender"), [player] call ULP_fnc_getName], getPlayerUID player]] remoteExecCall ["ULP_fnc_receiveMessage", _targets];
true