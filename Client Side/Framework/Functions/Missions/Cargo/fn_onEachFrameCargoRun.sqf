/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onEachFrameCargoRun";

_this params [ "_location", "_pos", "_type" ];

(ULP_Missions getOrDefault [_type, []]) params [ "_task", "", "", ["_vehicleInfo", [], [[]]] ];

if (isNull _task || { _vehicleInfo isEqualTo [] }) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

private _vehicle = _vehicleInfo param [0, objNull];

if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
	_task setTaskState "Failed";
	player removeSimpleTask _task;

	ULP_Missions deleteAt _type;

	["Your vehicle was lost and your cargo mission has failed."] call ULP_fnc_hint;

	[_thisEventHandler] call ULP_fnc_removeEachFrame;
};