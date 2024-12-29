/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_deleteMessage";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _inbox = _display displayCtrl 23048;
private _row = lnbCurSelRow _inbox;

private _forIndex = _inbox lnbValue [_row, 0];
private _messages = + (missionProfileNamespace getVariable ["ULP_Messages", []]);
private _message = _messages param [_forIndex, []];

if (_message isEqualTo []) exitWith {};

_messages deleteAt _forIndex;

missionProfileNamespace setVariable ["ULP_Messages", _messages];
saveMissionProfileNamespace;

_display call ULP_fnc_messages;