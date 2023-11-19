/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initServerEvents";

["Starting Random Server Events..."] call ULP_fnc_logIt;

private _delay = getNumber(missionConfigFile >> "CfgRandomEvents" >> "InitialDelay");

{
	private _variedDelay = ([0, _delay + (random (5) * 60)] select (isNil { missionNamespace getVariable "ULP_DebugMode" }));

	[format["Server Events: '%1' in '%2'", configName _x, _variedDelay]] call ULP_fnc_logIt;

	// Variation to stop them all spawning at once
	[_variedDelay, _x, {
		[_this] call ULP_SRV_fnc_spawnEvent;
	}] call ULP_fnc_waitExecute
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgRandomEvents"));