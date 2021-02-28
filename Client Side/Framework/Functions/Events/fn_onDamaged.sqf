/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onDamaged";

_this params [
    ["_unit", objNull, [objNull]],
    ["_part", "", [""]],
    ["_damage", 0, [0]],
    ["_source", objNull, [objNull]],
    ["_projectile", "", [""]],
    ["_index", 0, [0]]
];

// Get our current damage...
private _originalDamage = [
	_unit getHit _part,
	damage _unit
] select (_part isEqualTo "");

// TODO : Exit with original damage if knocked or tased...

// TODO : Handle Taser, Anti-VDM & Seatbelts...

if (_damage >= 1) then {
	_damage = 0.99; // They're hurt... 1 or over would kill them...

	// If they're already downed, kill them...
	if (isDowned(_unit)) then {
		// Checks...
		if (isNull _source || { diag_tickTime - (_unit getVariable ["Incap_time", 0]) < 1 } || { _part in ["arms", "legs", "hands"] }) exitWith {};

		_damage = 1; // Kill them...
	} else {
		if !(alive _unit) exitWith {}; // They're dead??

		[_unit, _source] call ULP_fnc_onIncapacitated; // Event...
		_unit setVariable ["Incap_time", diag_tickTime, true];
	};
};

_damage