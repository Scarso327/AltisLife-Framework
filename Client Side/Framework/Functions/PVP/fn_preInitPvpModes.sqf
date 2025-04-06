/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_preInitPvpModes";

if !(hasInterface) exitWith {};

["Pre-Initialising PVP Modes"] call ULP_fnc_logIt;

["PvpVoteStarted", { _this call ULP_fnc_onPvpVoteStarted; }] call ULP_fnc_addEventHandler;
["PvpVoteFinished", { _this call ULP_fnc_onPvpVoteFinished; }] call ULP_fnc_addEventHandler;

{
	private _event = _x;

	{
		[format["%1%2", configName _x, configName _event], compile getText _x] call ULP_fnc_addEventHandler;
	} forEach (configProperties [_x >> "Events", "true", true]);
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgPvpModes" >> "Modes"));