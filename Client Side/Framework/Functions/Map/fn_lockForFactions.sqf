/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_lockForFactions";

if (_this param [3, false] && { !isRemoteExecuted }) exitWith {
	_this remoteExecCall ["ULP_fnc_lockForFactions", -2, true];
};

if !(hasInterface) exitWith {};

[ { ULP_Loaded }, _this, {
	_this params [
		["_object", objNull, [objNull]],
		["_factions", ["Civilian"], [[]]],
		["_doorsToLock", [], [[]]]
	];

	if (isNull _object) exitWith {};

	{
		_object setVariable [format ["BIS_disabled_door_%1", _x], [[player, _factions] call ULP_fnc_isFaction] call ULP_fnc_bool];
	} count _doorsToLock;

	_object setVariable ["locked_doors", [_factions, _doorsToLock]];
} ] call ULP_fnc_waitUntilExecute;