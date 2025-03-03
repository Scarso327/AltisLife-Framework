/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_preInitRandomEvents";

if !(hasInterface) exitWith {};

["Pre-Initialising Server Events", true] call ULP_fnc_logIt;

{
	private _event = _x;

	{
		[format["%1%2", configName _x, configName _event], compile getText (_x >> "code")] call ULP_fnc_addEventHandler;
	} forEach ("isClass _x" configClasses (_x >> "Events"));
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgRandomEvents"));