/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_toggleOnStretcher";

_this params [
	["_unit", player, [objNull]]
];

private _stretcher = [_unit] call ULP_fnc_nearestStretcher;

if (isNull _unit || { isNull _stretcher } || { !([_stretcher] call ULP_fnc_isPlaceable) } || { !isDowned(_unit) }) exitWith { false };

private _attachedUnit = _stretcher getVariable ["unitAttached", objNull];
private _isAttaching = !(_attachedUnit isEqualTo _unit);

if (_isAttaching) exitWith {
	if !(isNull _attachedUnit) exitWith { ["No empty stretchers nearby"] call ULP_fnc_hint; false };

	_stretcher setVariable ["unitAttached", _unit, true];
	_unit attachTo [_stretcher, [0, 0.1, 0.2]];

	[format ["You have placed <t color='#B92DE0'>%1</t> on a stretcher", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;

	true
};

_stretcher setVariable["unitAttached", nil, true];
detach _unit;

true