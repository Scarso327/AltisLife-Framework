/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_failMissions";

if ((count ULP_Missions) > 0) then {
	{
		_y params [
			"_task", "_reward", "_eachFrame"
		];

		_task setTaskState "Failed";
		[3, _task, { player removeSimpleTask _this; }] call ULP_fnc_waitExecute;
	} forEach ULP_Missions;

	ULP_Missions = createHashMap;
};