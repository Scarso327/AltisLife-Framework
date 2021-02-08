/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getGatherZone";

private _cfg = ("isClass _x" configClasses (missionConfigFile >> "CfgGathering"));

for "_i" from 0 to ((count _cfg) - 1) do {
	private _cur = _cfg select _i;

	if !((getArray (_cur >> "areas") select { (player distance (getMarkerPos (_x select 0))) <= (_x select 1) }) isEqualTo []) exitWith {
		_cur breakOut "fn_getGatherZone";
	};
};

configNull