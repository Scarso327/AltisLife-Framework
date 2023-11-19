/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initServerEvents";

["Starting Random Server Events..."] call ULP_fnc_logIt;

private _delay = getNumber(missionConfigFile >> "CfgRandomEvents" >> "InitialDelay");

[_delay, [], {
	{
		[_x] call ULP_SRV_fnc_spawnEvent;
	} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgRandomEvents"));
}] call ULP_fnc_waitExecute