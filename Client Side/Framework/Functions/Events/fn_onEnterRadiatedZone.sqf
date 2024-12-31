/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onEnterRadiatedZone";

_this params [
	["_thisTrigger", objNull, [objNull]]
];

if (isNull _thisTrigger || { !(isNil { missionNamespace getVariable "ULP_Radiated" }) }) exitWith {};

player setVariable ["lastRadTick", nil];

missionNamespace setVariable ["ULP_Radiated", [[_thisTrigger], {
	_this params ["_thisTrigger"];

	// This is more a fallback - see fn_onLeftRadiatedZone for actual code
	if (!(alive _unit) || { isNull _thisTrigger } || { isNil { missionNamespace getVariable "ULP_Radiated" } }) exitWith {
		missionNamespace setVariable ["ULP_Radiated", nil];
		[_thisEventHandler] call ULP_fnc_removeEachFrame;
	};

	if ((player getVariable ["lastRadTick", -1]) > time 
		|| { [goggles player] call ULP_fnc_isGas && { [uniform player] call ULP_fnc_isGas } }
		|| { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } }) exitWith {};

	private _distance = player distance _thisTrigger;
	private _currentDamage = damage player;

	private _damage = _currentDamage + (0.01 max (1 / _distance) / 0.6 * 0.025 + (random 0.075));
	player setDamage _damage;

	private _nextTick = 0.1 max (_distance * 0.008);
	player setVariable ["lastRadTick", time + _nextTick];
}] call ULP_fnc_addEachFrame];

["EnteredRadiatedZone", []] call ULP_fnc_invokeEvent;