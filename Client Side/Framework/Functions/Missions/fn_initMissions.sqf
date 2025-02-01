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
				"_task", "_reward", "_eachFrame", ["_vehicleInfo", [], [[]]]
			];

			_task setTaskState "Failed";
			player removeSimpleTask _task;

			if !(_vehicleInfo isEqualTo []) then {
				_vehicleInfo params [ "_vehicle", "_missionType" ];

				if !(isNull _vehicle) then {
					private _cargoItem = getText (missionConfigFile >> "CfgMissions" >> _missionType >> "cargoItem");
					private _countRemoved = [_vehicle, _cargoItem] call ULP_fnc_wipeItemFromCargo;

					if (_countRemoved > 0) exitWith {
						["You died and all the cargo was lost from your vehicle."] call ULP_fnc_hint;
					};
				};
			};
		} forEach ULP_Missions;

		ULP_Missions = createHashMap;
	};
}] call ULP_fnc_addEventHandler;