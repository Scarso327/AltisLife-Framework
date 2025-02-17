/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hint";

if !(hasInterface) exitWith {};

if (canSuspend) exitWith {
    [ULP_fnc_hint, _this] call ULP_fnc_directCall;
};

_this params [
	["_text", "", [""]],
	["_header", "", [""]],
	["_sound", "FD_Timer_F", [""]]
];

private _display = ["RscHints"] call ULP_UI_fnc_getLayer;
if (isNull _display) exitWith {
	["RscHints", "PLAIN", 0] call ULP_UI_fnc_createLayer;
	_this call ULP_fnc_hint;
};

private _message = _display ctrlCreate [(["ULP_Notification", "ULP_NotificationNoHeader"] select (_header isEqualTo "")), -1];
private _ctrlText = _message controlsGroupCtrl 102;
_ctrlText ctrlSetStructuredText parseText _text;

private _height = ctrlTextHeight _ctrlText;

if !(_header isEqualTo "") then {
	_height = _height + ((ctrlPosition (_message controlsGroupCtrl 101)) select 1);
	(_message controlsGroupCtrl 101) ctrlSetStructuredText parseText format ["<t size='0.75'>%1</t>", _header];
};

_ctrlText ctrlSetPositionH (ctrlTextHeight _ctrlText);
_ctrlText ctrlCommit 0;
_message ctrlSetPositionH _height;
_message ctrlSetFade 1;
_message ctrlCommit 0;

_message setVariable ["duraction", diag_tickTime + 10];

if !(_sound isEqualTo "") then { playSound _sound; };

private _hints = + (_display getVariable ["hints", []]);

reverse _hints;
_hints pushBack _message;
reverse _hints;

_display setVariable ["hints", _hints];

private _offset = (ctrlPosition _message) select 1;
private _last = (count _hints) - 1;

{
	private _hint = _x;

	(ctrlPosition _hint) params ["", "_y", "", "_h"];
	
	_hint ctrlSetPositionY _offset;
	_hint ctrlSetFade 0;
	_hint ctrlCommit 0.2;
	
	_offset = _offset + (_h + (0.0055 * safezoneH));
} forEach + (_display getVariable ["hints", []]);