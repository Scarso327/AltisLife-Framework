/*
** Author: Jack "Scarso" Farhall
** Description: Sends our target unit to prison...
*/
#include "..\..\script_macros.hpp"
scopeName "fn_imprison";

if (canSuspend) exitWith {
    [ULP_fnc_imprison, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", player, [objNull]],
	["_duration", 5 * 60, [0]],
	["_arrester", objNull, [objNull]],
	["_update", true, [false]]
];

if (isNull _unit || { !(isPlayer _unit) } || { !([_unit] call ULP_fnc_canImprisoned) } || { _duration <= 0 }) exitWith { false };
if !(local _unit) exitWith { _this remoteExecCall ["ULP_fnc_imprison", _unit]; false; };

private _prison = missionConfigFile >> "CfgPrison" >> worldName;
if !(isClass _prison) exitWith { false };

if (_duration > getNumber (_prison >> "maxDuraction")) exitWith { false };

[player, objNull, false] call ULP_fnc_restrain;

getArray (_prison >> "imprison") params ["_pos", "_dir"];
_unit setPos _pos;
_unit setDir _dir;

[_prison >> "PrisonLoadout"] call ULP_fnc_setCfgLoadout;

ULP_Imprisioned = true;
ULP_Prison_Time = time + _duration;

if (isNil "ULP_Prison_SellEvent") then {
	ULP_Prison_SellEvent = ["SoldVirtualItem", {
		_this params [
			"_item", "_total"
		];

		ULP_Prison_Time = ULP_Prison_Time - (1.25 * _total);
	}] call ULP_fnc_addEventHandler;
};

["Convict"] call ULP_fnc_achieve;

if (isNull (["RscFiringDrillTime"] call ULP_UI_fnc_getLayer)) then {
	["RscFiringDrillTime", "PLAIN", 3] call ULP_UI_fnc_createLayer;
};

// Recolour...
private _display = ["RscFiringDrillTime"] call ULP_UI_fnc_getLayer;
(_display displayCtrl 1100) ctrlSetBackgroundColor [0.1,0.1,0.1,0.85];

if ((uiNamespace getVariable ["prison_timer", -1]) isEqualTo -1) then {
	uiNamespace setVariable ["prison_timer", [[_unit, _pos], {
		_this params ["_unit", "_pos"];

		private _hasTimeElapsed = ULP_Imprisioned && (ULP_Prison_Time - time) <= 0;
		private _hasEscaped = ULP_Imprisioned && !_hasTimeElapsed && { (_unit distance _pos) > 100 };

		if (isNull _unit || { !ULP_Imprisioned } || { _hasTimeElapsed } || { _hasEscaped }) exitWith {
			[_unit, _hasEscaped] call ULP_fnc_release;
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};

		private _timeLeft = ULP_Prison_Time - time;
		missionNamespace setVariable["RscFiringDrillTime_current", parseText format["<img image='A3\Modules_F_Beta\data\FiringDrills\timer_ca'/> %1", [_timeLeft, "MM:SS"] call BIS_fnc_secondsToString]];
	}] call ULP_fnc_addEachFrame];
};

if (_update) then {
	[_unit, 7, _duration] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

if !(isNull _arrester) then {
	[format["You've been sentenced for <t color='#B92DE0'>%1</t> by <t color='#B92DE0'>%2</t>", [_duration, "MM:SS"] call BIS_fnc_secondsToString, name _arrester]] call ULP_fnc_hint;
};

true