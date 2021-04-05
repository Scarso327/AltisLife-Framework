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

if ([_unit] call ULP_fnc_isKnocked) exitWith { _originalDamage };

if (!(isNull (objectParent _unit)) && { (vehicle _unit) isKindOf "LandVehicle" }) then {
	private _multiplier = [
		1.25,
		1
	] select (_unit getVariable["seatBelt", false]);

	_damage = (_originalDamage + ((_damage - _originalDamage) * _multiplier)) * ([
		1.1,
		0.9
	] select ((speed (vehicle _unit)) <= 80));
};

if (!isNull _source) then {
	if ((currentWeapon _source) in getArray(missionConfigFile >> "CfgSettings" >> "taserWeapons")) exitWith {
		if ((_unit distance _source) <= 50) then {
			[_source, true] call ULP_fnc_onKnocked;
		};

		_originalDamage breakOut "fn_onDamaged";
	};
};

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