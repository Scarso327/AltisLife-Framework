/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_spawnEvent";

_this params [
	["_cfg", configNull, [configNull]],
	["_ignoreCondition", false, [true]]
];

if (isNull _cfg) exitWith { false };

private _activeVarName = format ["ULP_SRV_%1_Active", configName _cfg];

if !(isNil { ULP_DebugMode }) then {
    [format["fn_spawnEvent: '%1', '%2'", _cfg, _ignoreCondition]] call ULP_fnc_logIt;
};

// _ignoreCondition or cfg condition is met and none are active
[ { !(missionNamespace getVariable [(_this select 3), false]) && { (_this select 1) || { call (_this select 2) } } }, 
	[_cfg, _ignoreCondition, compile getText ([_cfg, "SpawnCondition", "true"] call ULP_SRV_fnc_getEventParam), _activeVarName], {

	_this params [
		["_cfg", configNull, [configNull]],
		["_ignoreCondition", false, [true]],
		"",
		["_activeVarName", format ["ULP_SRV_%1_Active", configName _cfg], [""]]
	];

	if (isNull _cfg || { missionNamespace getVariable [_activeVarName, false] }) exitWith {};

	if ([_cfg, !_ignoreCondition] call compile getText (_cfg >> "ServerFunctions" >> "onSpawn")) then {
		missionNamespace setVariable [_activeVarName, true, true];
	};
} ] call ULP_fnc_waitUntilExecute;

true