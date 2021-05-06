/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_release";

if (canSuspend) exitWith {
    [ULP_fnc_release, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", player, [objNull]],
	["_escaped", false, [true]]
];

if (isNull _unit || { !(isPlayer _unit) }) exitWith { false };
if !(local _unit) exitWith { _this remoteExecCall ["ULP_fnc_release", _unit]; false; };

["RscFiringDrillTime"] call ULP_UI_fnc_destroyLayer;
[uiNamespace getVariable ["prison_timer", -1]] call ULP_fnc_removeEachFrame;

missionNamespace setVariable ["RscFiringDrillTime_current", nil];
uiNamespace setVariable ["prison_timer", nil];

private _prison = missionConfigFile >> "CfgPrison" >> worldName;
if !(isClass _prison) exitWith { false };

if (_escaped) then {
	["You've escaped from prison!"] call ULP_fnc_hint;

	[getPlayerUID player, "CommonLaw", "EscapeEscort", "Escaped HMP Altis."] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
} else {
	getArray (_prison >> "release") params ["_pos", "_dir"];
	_unit setPos _pos;
	_unit setDir _dir;

	["You've served your sentence and been released!"] call ULP_fnc_hint;
	[_prison >> "ReleaseLoadout"] call ULP_fnc_setCfgLoadout;

	[getPlayerUID player] remoteExecCall ["ULP_SRV_fnc_clearWarrants", RSERV];
};

ULP_Prison_Time = 0;
ULP_Imprisioned = false;

if !(isNil "ULP_Prison_SellEvent") then {
	["", ULP_Prison_SellEvent] call ULP_fnc_removeEventHandler;
	ULP_Prison_SellEvent = nil;
};

[_unit, 7, 0] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
true