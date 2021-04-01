/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initServerEvents";

["Starting Random Server Events..."] call ULP_fnc_logIt;

{
	missionNamespace setVariable [format ["ULP_SRV_%1_Active", configName _x], false, true];
	_x call ULP_SRV_fnc_spawnEvent;
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgRandomEvents"));