/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_SetAssignedMedic";

_this params [ "_button" ];

if (isNull _button) exitWith {};

private _display = ctrlParent _button;

private _list = _display displayCtrl 5402;

private _index = tvCurSel _list;
private _unit = (_list tvData _index) call BIS_fnc_objectFromNetId;

if (isNull _unit || { !(isDowned(_unit)) }) exitWith {};

private _assignedMedic = _unit getVariable ["AssignedMedic", objNull];
private _isAssignedToUs = _assignedMedic isEqualTo player;

if (_assignedMedic isEqualTo player) exitWith {
	// Unassign

	_unit setVariable ["AssignedMedic", nil, true];
	["AssignedMedicChanged", [_unit], true] call ULP_fnc_invokeEvent;

	[format ["You've unassigned yourself from %1", name _unit]] call ULP_fnc_hint;
};

if ((_display getVariable ["Cooldown", 0]) > time) exitWith {
	["Please wait before preforming this action again"] call ULP_fnc_hint;
};

if (!isNull _assignedMedic) exitWith {
	["This player is already assigned to someone else"] call ULP_fnc_hint;
};

// If we're already assigned, unassign ourselves first
private _incapacitatedPlayers = _display getVariable["IncapacitatedPlayers", []];
private _current = _incapacitatedPlayers findIf { (_x getVariable ["AssignedMedic", objNull]) isEqualTo player };

if !(_current isEqualTo -1) then {
	private _currentUnit = (_list tvData _current) call BIS_fnc_objectFromNetId;

	if (isNull _currentUnit) exitWith {};

	_currentUnit setVariable ["AssignedMedic", nil, true];
	["AssignedMedicChanged", [_currentUnit], true] call ULP_fnc_invokeEvent;
};

_unit setVariable ["AssignedMedic", player, true];
["AssignedMedicChanged", [_unit, player], true] call ULP_fnc_invokeEvent;

[format ["You're assigned to %1", name _unit]] call ULP_fnc_hint;

_display setVariable ["Cooldown", time + 5];