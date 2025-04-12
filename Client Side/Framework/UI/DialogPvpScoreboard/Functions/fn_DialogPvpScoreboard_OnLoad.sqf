/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogPvpScoreboard_OnLoad";

_this params [ "_display" ];

if (isNull _display) exitWith {};

disableSerialization;
uiNamespace setVariable ["DialogPvpScoreboard", _display];

private _bannerCtrl = _display displayCtrl 6402;
private _timerCtrl = _display displayCtrl 6407;

private _currentPvpMode = missionNamespace getVariable ["ULP_SRV_CurrentPvpMode", []];

_currentPvpMode params [
	["_mode", configNull, [configNull]],
	["_location", configNull, [configNull]]
];

if (isNull _mode || { isNull _location }) exitWith { _display closeDisplay 1; };

_bannerCtrl ctrlSetStructuredText parseText format ["<t size='1.25'>%1<br/><t size ='1'>%2</t></t>", getText (_mode >> "displayName"), getText (_location >> "displayName")];

[_display] call ULP_UI_fnc_DialogPvpScoreboard_UpdateList;

_display setVariable ["eachFrameHandle", ([[_display, _timerCtrl], {
	_this params [ "_display", "_timerCtrl" ];

	private _timeLeft = ((missionNamespace getVariable ["ULP_SRV_PvpConflictTick", serverTime]) - serverTime) max 0;

	_timerCtrl ctrlSetStructuredText parseText format ["<t align='right' size='2.25'>%1</t>", [_timeLeft, "MM:SS"] call BIS_fnc_secondsToString];

	if (isNil { missionNamespace getVariable "ULP_SRV_CurrentPvpMode" }) then {
		_display closeDisplay 1;
	};

	if !((_display getVariable ["lastList", createHashMap]) isEqualTo ULP_SRV_CurrentScores) then {
		[_display] call ULP_UI_fnc_DialogPvpScoreboard_UpdateList;
	};
}] call ULP_fnc_addEachFrame)];