/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setMedicalAssignment";

if (canSuspend) exitWith {
    [ULP_fnc_setMedicalAssignment, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(isDowned(_unit)) }) exitWith { false };

private _assignedMedic = _unit getVariable ["AssignedMedic", objNull];
private _isAssignedToUs = _assignedMedic isEqualTo player;

if (_assignedMedic isEqualTo player) exitWith {
	// Unassign

	_unit setVariable ["AssignedMedic", nil, true];
	["AssignedMedicChanged", [_unit], true] call ULP_fnc_invokeEvent;

	[format ["You've unassigned yourself from %1", name _unit]] call ULP_fnc_hint;
	true
};

if (!isNull _assignedMedic) exitWith {
	["This player is already assigned to someone else"] call ULP_fnc_hint;
	false
};

// If we're already assigned, unassign ourselves first
private _current = allPlayers findIf { (_x getVariable ["AssignedMedic", objNull]) isEqualTo player };

if !(_current isEqualTo -1) then {
	private _currentUnit = allPlayers param [_current, objNull, [objNull]];
	if (isNull _currentUnit) exitWith {};

	_currentUnit setVariable ["AssignedMedic", nil, true];
	["AssignedMedicChanged", [_currentUnit], true] call ULP_fnc_invokeEvent;
};

_unit setVariable ["AssignedMedic", player, true];
["AssignedMedicChanged", [_unit, player], true] call ULP_fnc_invokeEvent;

[format ["You're assigned to %1", name _unit]] call ULP_fnc_hint;
true