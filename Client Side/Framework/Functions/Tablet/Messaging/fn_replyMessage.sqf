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
	hint "You need to select a message to reply to...";
};

_message params [
	"_type", "_sender"
];

private _cfg = missionConfigFile >> "CfgMessages" >> _type;
if !(isClass _cfg) exitWith {};

if !([getNumber (_cfg >> "canReply")] call ULP_fnc_bool) exitWith {
	hint "This message can't be replied to...";
};

_sender params [ "_name", "_steamid" ];

private _unit = [_steamid] call ULP_fnc_playerByUID;
if (isNull _unit) exitWith {
	hint "You can't reply to this message as the sender is no longer online...";
};

private _msgCtrl = _display displayCtrl 23041;
private _message = [ctrlText _msgCtrl] call ULP_fnc_stripString;

if (_message isEqualTo "" || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {
	hint "You need to type a message you want to send...";
};

[missionConfigFile >> "CfgMessages" >> "Reply", _message, _unit] call ULP_fnc_sendMessage;
_msgCtrl ctrlSetText "";