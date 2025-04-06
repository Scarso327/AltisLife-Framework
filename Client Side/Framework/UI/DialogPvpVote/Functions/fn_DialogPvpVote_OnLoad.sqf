/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogPvpVote_OnLoad";

_this params [ "_display" ];

if (isNull _display) exitWith {};

disableSerialization;
uiNamespace setVariable ["DialogPvpVote", _display];

private _modes = missionNamespace getVariable ["ULP_PVPModes", []];

if (_modes isEqualTo []) exitWith {
	["There is currently not active vote"] call ULP_fnc_hint;
	_display closeDisplay 1;
};

private _list = _display displayCtrl 6303;
tvClear _list;

{
	_x params [ "_mode", "_location" ];

	private _modeName = getText (_mode >> "displayName");
	private _locationName = getText (_location >> "displayName");

	private _index = _list tvAdd [[], format["%1 at %2", _modeName, _locationName]];
	_list tvSetData [[_index], format["%1%2", configName _mode, configName _location]];
} forEach ULP_PVPModes;

private _ctrlTitle = _display displayCtrl 6301;

_display setVariable ["eachFrameHandle", ([[_display, _ctrlTitle], {
	_this params [ "_display", "_ctrlTitle" ];

	private _duration = getNumber (missionConfigFile >> "CfgPvpModes" >> "voteDuration");
	private _timeLeft = ((missionNamespace getVariable ["ULP_PvpMode_VoteStartTime", serverTime]) + _duration) - serverTime;

	_ctrlTitle ctrlSetText format ["PVP Voting - %1", [_timeLeft] call BIS_fnc_secondsToString];

	if (isNil { missionNamespace getVariable "ULP_PVPModes" }) then {
		_display closeDisplay 1;
	};
}] call ULP_fnc_addEachFrame)];