/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startSalvageFactory";

_this params [
	["_factory", objNull, [objNull]],
	["_unit", objNull, [objNull]],
	["_productCfg", configNull, [configNull]],
	["_params", [], [[]]]
];

private _vehicle = _params param [0, objNull, [objNull]];

if (isNull _vehicle || { !alive _vehicle } || { !(count (crew _vehicle) isEqualTo 0) } || { (_factory distance _vehicle) > 50 }) exitWith {
	["FactoryStarted", ["This vehicle is destroyed, has occupants or is too far away"]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];

	0
};

_factory setVariable ["factory_vehicle", _vehicle];

1