/*
    @File: fn_notify.sqf

    @Author: Jack "Scarso" Farhall

    @Date Created: 8th February 2019

    @Description: Displays text about certain events...
*/
#include "..\..\script_macros.hpp"
params [
	["_message", "", [""]],
	["_newCtrlPos", [1.275,0.92,0.4,0.1], [[]]]
];

private _text = parseText _message;

//Queue it
private _queue = FF_eventFeedQueue;
FF_eventFeedQueue = FF_eventFeedQueue + 1;

if (FF_eventFeedQueue > 1) then { waitUntil {FF_eventFeedQueue isEqualTo _queue} };

disableSerialization;

private _ctrl = ObjNull;

{
	_ctrl = (findDisplay 46) displayCtrl _x;
	_pos = ctrlPosition _ctrl;
	_pos set [1, (_pos select 1) + 0.05];
	_ctrl ctrlSetPosition _pos;
	_ctrl ctrlCommit 0.25;
}forEach FF_activeEventFeedControls;

UISleep (0.25);

_ctrl = (findDisplay 46) ctrlCreate ["RscStructuredText", FF_eventControl];
_ctrl ctrlSetPosition _newCtrlPos;
_ctrl ctrlSetStructuredText _text; 
_ctrl ctrlCommit 0;

_ctrl ctrlSetFade 1;
_ctrl ctrlCommit 7;

//Runs for the newly created control
[FF_eventControl] spawn {
	disableSerialization;

	_idc = _this select 0;
	_ctrl = (findDisplay 46) displayCtrl _idc;

	UISleep 7;
	ctrlDelete _ctrl;

	FF_activeEventFeedControls = FF_activeEventFeedControls - [_idc];

	if (count FF_activeEventFeedControls isEqualTo 0) then { FF_eventControl = 20000 };
};

//Add new control
FF_activeEventFeedControls pushBack FF_eventControl;
FF_eventControl = FF_eventControl + 1;

//Queue thing
UISleep (0.25);
FF_eventFeedQueue = FF_eventFeedQueue - 1;

playSound "FD_Timer_F";