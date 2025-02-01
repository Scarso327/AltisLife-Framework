/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initMissions";

["Initialising Missions"] call ULP_fnc_logIt;

["Died", {
	_this params [ "_unit" ];

	if !(_unit isEqualTo player) exitWith {};

	if ((count ULP_Missions) > 0) then {
		{
			_y params [
				"_task"
			];

			_task setTaskState "Failed";
			player removeSimpleTask _task;
		} forEach ULP_Missions;

		ULP_Missions = createHashMap;
	};
}] call ULP_fnc_addEventHandler;