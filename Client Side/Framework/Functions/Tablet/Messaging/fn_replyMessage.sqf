/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_replyMessage";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _inbox = _display displayCtrl 23048;
private _row = lnbCurSelRow _inbox;

private _forIndex = _inbox lnbValue [_row, 0];
private _messages = + (profileNamespace getVariable ["ULP_Messages", []]);
private _message = _messages param [_forIndex, []];

if (_message isEqualTo []) exitWith {
	["You need to select a message to reply to!"] call ULP_fnc_hint;
};

_message params [
	"_type", "_sender"
];

private _cfg = missionConfigFile >> "CfgMessages" >> _type;
if !(isClass _cfg) exitWith {};

if !([getNumber (_cfg >> "canReply")] call ULP_fnc_bool) exitWith {
	["This message can't be replied to!"] call ULP_fnc_hint;
};

_sender params [ "_name", "_steamid" ];

private _unit = [_steamid] call ULP_fnc_playerByUID;
if (isNull _unit) exitWith {
	["You can't reply to this message as the sender is no longer online!"] call ULP_fnc_hint;
};

private _msgCtrl = _display displayCtrl 23041;
private _message = [ctrlText _msgCtrl] call ULP_fnc_stripString;

if (_message isEqualTo "" || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {
	["You need to type a message you want to send!"] call ULP_fnc_hint;
};

[missionConfigFile >> "CfgMessages" >> "Reply", _message, _unit] call ULP_fnc_sendMessage;
_msgCtrl ctrlSetText "";