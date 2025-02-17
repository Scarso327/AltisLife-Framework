/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_sendMessage";

_this params [
	["_type", configNull, [configNull, ""]],
	["_message", "", [""]],
	["_targets", "", ["", objNull, []]]
];

if (_type isEqualType "") then { _type = missionConfigFile >> "CfgMessages" >> _type; };
if (_targets isEqualTo "" && { isClass _type }) then { _targets = getText (_type >> "targets"); };

if (!isClass _type || 
	{ _message isEqualTo "" } || 
	{ _targets isEqualType "" && { _targets isEqualTo "" } } || 
	{ _targets isEqualType objNull && { isNull _targets } } || 
	{ _targets isEqualType [] && { _targets isEqualTo [] } }
) exitWith { false };

if (_targets isEqualType "") then {
	_targets = call compile _targets;
};

if ([getNumber (_type >> "confirmSend")] call ULP_fnc_bool) then {
	[format ["Message Sent"]] call ULP_fnc_hint;
};

[_type, _message, [format[getText (_type >> "sender"), [player] call ULP_fnc_getName], getPlayerUID player]] remoteExecCall ["ULP_fnc_receiveMessage", _targets];
true