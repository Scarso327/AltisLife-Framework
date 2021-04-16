/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onSurvival";

_this params [
	["_surVar", "ULP_Survival_Hunger", [""]]
];

private _cfg = missionConfigFile >> "CfgSurvival" >> _surVar;
if !(isClass _cfg) exitWith {};

private _delay = getNumber(_cfg >> "delay");

if (alive player && { !(isDowned(player)) } && { !ULP_FirstSpawn }) then {
	if (isNil { missionNamespace getVariable (configName _cfg) }) then {
		missionNamespace setVariable [(configName _cfg), getNumber(_cfg >> "max")];
	} else {
		if ([player] call ULP_fnc_onDuty) exitWith {};
		
		private _var = (missionNamespace getVariable (configName _cfg));

		_var = _var - getNumber(_cfg >> "decrease");

		if (_var <= 0) then {
			_var = 0; // Force 0...
			[] call compile (getText(_cfg >> "onZero"));
		};

		missionNamespace setVariable [(configName _cfg), _var];
	};
};

if (_delay > 0) then {
	[
		_delay, [_surVar],
		{ [_this select 0] call ULP_fnc_onSurvival }
	] call ULP_fnc_waitExecute;
};