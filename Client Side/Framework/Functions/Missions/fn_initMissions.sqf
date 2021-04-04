/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initMissions";

["Initialising Missions"] call ULP_fnc_logIt;

["Died", {
	if ((count ULP_Missions) > 0) then {
		{
			_y params [
				"_task", "_reward", "_eachFrame"
			];

			_task setTaskState "Failed";
			player removeSimpleTask _task;
		} forEach ULP_Missions;

		ULP_Missions = createHashMap;
	};
}] call ULP_fnc_addEventHandler;