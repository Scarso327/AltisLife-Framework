/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_neutralise";

_this params [
	["_location", objNull, [objNull]]
];

private _capture = _location getVariable ["site", ""];

private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
if (isNull _location || { !(isClass _cfg) } || { !isNumber (_cfg >> "cooldown") }) exitWith { false };

if !([player, ["Police"]] call ULP_fnc_isFaction) exitWith {
	["Only the police can neutralise sites..."] call ULP_fnc_hint;
	false
};

private _owner = _location getVariable ["site_owner_id", -1];

if (_owner isEqualTo -1) exitWith {
	["This site isn't owned by anyone..."] call ULP_fnc_hint;
	false
};

([format ["Neutralising %1", getText(_cfg >> "displayName")], getNumber (_cfg >> "time"), [_location, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [ "_location", "_cfg" ];

	_location setVariable ["timeout", serverTime + (getNumber (_cfg >> "cooldown")), true];
	_location setVariable ["site_owner_id", nil, true];

	[format ["You have successfully neutralised <t color='#B92DE0'>%1</t>", getText (_cfg >> "displayName")]] call ULP_fnc_hint;
	[150, "Neutralised Site"] call ULP_fnc_addXP;

	if (isClass (_cfg >> "Marker")) then {
		private _marker = _location getVariable ["marker", ""];
		private _defaultName = getText (_cfg >> "Marker" >> "defaultName");

		_marker setMarkerText _defaultName;
	};

	["SiteNeutralised", [_location, player], true] call ULP_fnc_invokeEvent;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress)