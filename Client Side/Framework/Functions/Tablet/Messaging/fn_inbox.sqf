/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_inbox";

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _replyButton = _display displayCtrl 23039;
private _textBox = _display displayCtrl 23040;

private _forIndex = _ctrl lnbValue [_index, 0];
private _messages = + (missionProfileNamespace getVariable ["ULP_Messages", []]);
private _message = _messages param [_forIndex, []];

if (_message isEqualTo []) exitWith {};

_message params [
	"_type", "_sender", "_text", ["_read", false, [true]]
];

private _cfg = missionConfigFile >> "CfgMessages" >> _type;
if !(isClass _cfg) exitWith {};

_replyButton ctrlEnable ([getNumber (_cfg >> "canReply")] call ULP_fnc_bool);

if !(_read) then {
	_message set [3, true];
	_messages set [_forIndex, _message];

	missionProfileNamespace setVariable ["ULP_Messages", _messages];
	saveMissionProfileNamespace;

	_ctrl lnbSetPicture [[_index, 2], "\a3\3DEN\Data\Controls\ctrlCheckbox\textureChecked_ca.paa"];
};

_textBox ctrlSetStructuredText parseText format["From: %1<br/>%2", _sender select 0, _text];