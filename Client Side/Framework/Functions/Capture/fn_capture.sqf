/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_capture";

_this params [
	["_location", objNull, [objNull]],
	["_capture", "", [""]]
];

private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
if (isNull _location || { !(isClass _cfg) }) exitWith { false };

if !([] call ULP_fnc_isGroup) exitWith {
	["You must be in a group to capture this site..."] call ULP_fnc_hint;
	false
};

if !(call compile getText (_cfg >> "condition")) exitWith {
	["You're unable to capture this site at this time..."] call ULP_fnc_hint;
	false
};

private _owner = _location getVariable ["site_owner_id", -1];
if (([] call ULP_fnc_groupId) isEqualTo _owner) exitWith {
	["You already own this site..."] call ULP_fnc_hint;
	false
};

([format ["Capturing"], getNumber (_cfg >> "time"), [_location, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [ "_location", "_cfg" ];

	// Verify...
	if !([] call ULP_fnc_isGroup) exitWith { ["You must be in a group to capture this site..."] call ULP_fnc_hint; };

	_location setVariable ["site_owner_id", ([] call ULP_fnc_groupId), true];
	[format ["You have successfully captured <t color='#B92DE0'>%1</t>", getText (_cfg >> "displayName")]] call ULP_fnc_hint;
	[100, "Captured Hideout"] call ULP_fnc_addXP;

	[(group player), "Hideout"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];
	[getPlayerUID player, "CaptureHideout", [getText (_cfg >> "displayName")]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress)