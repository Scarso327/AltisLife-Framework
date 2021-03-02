/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleSiren";

_this params [
	["_vehicle", objNull, [objNull]],
	["_siren", "", [""]],
	["_on", true, [false]]
];

if (isNull _vehicle) exitWith {};

deleteVehicle (_vehicle getVariable ["siren", objNull]);

if (_on) then {
	diag_log _siren;
	private _source = createSoundSource [_siren, getPosATL _vehicle, [], 0];
	_source attachTo [_vehicle, [0, 0, 0]];
	_vehicle setVariable ["siren", _source, true];
};