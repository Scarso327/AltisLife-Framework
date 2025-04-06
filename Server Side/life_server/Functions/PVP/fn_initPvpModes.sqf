/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initPvpModes";

["Initialising PVP Modes..."] call ULP_fnc_logIt;

private _day = [] call ULP_SRV_fnc_getDayName;
private _daysAllowed = getArray (missionConfigFile >> "CfgPvpModes" >> "days");

if !(_day in _daysAllowed) exitWith {};

private _startTime = getArray (missionConfigFile >> "CfgPvpModes" >> "time");
_startTime params [ "_expectedHour", "_expectedMinute" ];

// Wait for start times

[{
	systemTime params [ "", "", "", "_hour", "_minute" ];
	_this params [ "_expectedHour", "_expectedMinute" ];

	_hour >= _expectedHour && { _minute >= _expectedMinute }
}, [_expectedHour, _expectedMinute], {
	[] call ULP_SRV_fnc_startPvpModeVoting;
}] call ULP_fnc_waitUntilExecute;