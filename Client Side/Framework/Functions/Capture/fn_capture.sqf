/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_capture";

_this params [
	["_location", objNull, [objNull]]
];

private _capture = _location getVariable ["site", ""];

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

private _cooldown = _location getVariable ["timeout", 0];
if (serverTime < _cooldown) exitWith {
	["This site has recently been neutralised and can't be captured for another <t color='#B92DE0'>%1</t> seconds...", [_cooldown - serverTime] call ULP_fnc_numberText] call ULP_fnc_hint;
	false
};

([format ["Capturing %1", getText(_cfg >> "displayName")], getNumber (_cfg >> "time"), [_location, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [ "_location", "_cfg" ];

	// Verify...
	if !([] call ULP_fnc_isGroup) exitWith { ["You must be in a group to capture this site..."] call ULP_fnc_hint; };

	private _siteName = getText (_cfg >> "displayName");
	private _groupTag = [] call ULP_fnc_groupTag;

	_location setVariable ["site_owner_id", ([] call ULP_fnc_groupId), true];
	[format ["You have successfully captured <t color='#B92DE0'>%1</t>", _siteName]] call ULP_fnc_hint;
	[100, "Captured Site"] call ULP_fnc_addXP;

	if (isClass (_cfg >> "Marker")) then {
		private _marker = _location getVariable ["marker", ""];
		private _defaultName = getText (_cfg >> "Marker" >> "defaultName");

		_marker setMarkerText format ["%1 | %2", _defaultName, _groupTag];
	};

	[(group player), "Hideout"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];
	[getPlayerUID player, "CaptureHideout", [_siteName]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

	["SiteCaptured", [_location, _groupTag], true] call ULP_fnc_invokeEvent;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress)