/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setFactoryPower";

_this params [
	["_factory", objNull, [objNull]],
	["_powerTier", 0, [0]]
];

if (isNull _factory) exitWith { 0 };

private _power = _factory getVariable ["power", 0];

_power = _power + _powerTier;
private _isPowered = _power > 0;

_factory setVariable ["power", (if (_isPowered) then {
	_power
} else {
	nil
}), true];

private _currentMarker = _factory getVariable ["marker", ""];

if (_currentMarker isEqualTo "") exitWith {};

_currentMarker setMarkerColor (if (_isPowered) then {
		getText (missionConfigFile >> "CfgFactories" >> "colourPowered")
	} else {
		getText (missionConfigFile >> "CfgFactories" >> "colourDefault")
	});