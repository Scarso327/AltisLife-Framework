/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onEachFrameFreight";

_this params [ "_location", "_pos" ];

private _vehicle = (missionNamespace getVariable ["ULP_FreightVehicle", [objNull, 0]]) param [0, objNull];

if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
	private _freightMission = ULP_Missions getOrDefault ["CorporateFreight", []];

	if !(_freightMission isEqualTo []) then {
		_freightMission params [
			"_task", "_reward", "_eachFrame"
		];

		_task setTaskState "Failed";
		player removeSimpleTask _task;

		ULP_Missions deleteAt "CorporateFreight";

		["Your vehicle was lost and your freight mission has failed."] call ULP_fnc_hint;
	};

	[_thisEventHandler] call ULP_fnc_removeEachFrame;
};