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

	// Handle freight vehicle
	private _vehicle = (missionNamespace getVariable ["ULP_FreightVehicle", [objNull, 0]]) param [0, objNull];

	if !(isNull _vehicle) then {
		private _countRemoved = [_vehicle, "FreightCargo"] call ULP_fnc_wipeItemFromCargo;

		if (_countRemoved > 0) exitWith {
			["You died and all the freight was lost from your truck."] call ULP_fnc_hint;
		};
	};
}] call ULP_fnc_addEventHandler;