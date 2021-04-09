/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_recieveMessage";

_this params [
	["_type", configNull, [configNull]],
	["_message", "", [""]],
	["_sender", [], [[]]]
];

if (isNull _type || { _message isEqualTo "" } || { _sender isEqualTo [] } || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {};

private _messages = + (profileNamespace getVariable ["ULP_Messages", []]);
_messages pushBack [configName _type, _sender, _message, false];

private _count = count _messages;
if (_count > 25) then {
	_messages = _messages select [_count - 25, 25];
};

profileNamespace setVariable ["ULP_Messages", _messages];
saveProfileNamespace;

if ([["EnableStreamerMode"] call ULP_fnc_getOption] call ULP_fnc_bool && { !([getNumber (_type >> "ignoreStreamer")] call ULP_fnc_bool) }) then {
	hint "You received a message";
} else {
	_sender params [
		["_name", "", [""]]
	];

	hint format ["You received a message from %1: %2", _name, _message];
};

if (isText (_type >> "onRecieved")) then {
	[[_sender select 1] call ULP_fnc_playerByUID, _message] call compile getText (_type >> "onRecieved");
};

["MessageReceived", _messages] call ULP_fnc_invokeEvent;