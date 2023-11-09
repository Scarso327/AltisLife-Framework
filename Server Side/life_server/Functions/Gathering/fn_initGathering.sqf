/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initGathering";

["Initialising Gather Zones..."] call ULP_fnc_logIt;

{
	private _locations = getArray (_x >> "positions");
	private _areas = getArray (missionConfigFile >> "CfgGathering" >> (configName _x) >> "areas");

	if (_locations isEqualTo []) exitWith {};

	// We must have equal or more positions than total areas to randomise...
	if ((count _locations) >= (count _areas)) then {
		{
			private _location = selectRandom _locations;
			_locations deleteAt (_locations find _location);

			(_x select 0) setMarkerPos _location;
		} forEach _areas;
	};
} forEach ("isClass _x" configClasses (configFile >> "CfgPatches" >> "ULPServer" >> "CfgGathering"));