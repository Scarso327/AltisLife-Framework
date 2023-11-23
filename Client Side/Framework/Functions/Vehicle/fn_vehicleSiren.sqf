/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleSiren";

_this params [
	["_vehicle", objNull, [objNull]],
	["_sirens", [], [[]]],
	["_on", true, [false]]
];

if (isNull _vehicle) exitWith {};

deleteVehicle (_vehicle getVariable ["siren", objNull]);

if (_on && { !(_sirens isEqualTo []) }) then {
	private _siren = _sirens param [(_vehicle getVariable ["selected_siren", 0]), "", [""]];
	if (_siren isEqualTo "") exitWith {};

	private _source = createSoundSource [_siren, getPosATL _vehicle, [], 0];
	_source attachTo [_vehicle, [0, 0, 0]];
	_vehicle setVariable ["siren", _source, true];
} else {
	_vehicle setVariable ["selected_siren", nil];
};