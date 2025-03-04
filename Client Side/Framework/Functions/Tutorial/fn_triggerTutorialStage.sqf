/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_triggerTutorialStage";

_this params [
	["_stage", configNull, [configNull]]
];

if (!isClass _stage || { !([] call ULP_fnc_isOnTutorial) }) exitWith {};

private _displayName = getText (_stage >> "displayName");
private _description = getText (_stage >> "description");

[format ["<t color='#008000' size='1.5px'>Tutorial<br/></t><t color='#ffffff' size='1px'>%1", _description]] call ULP_fnc_hint;

private _condition = compile getText (_stage >> "condition");

private _task = player createSimpleTask [format ["Tutorial_%1", configName _stage]];
_task setSimpleTaskDestination getArray (_stage >> "location");
_task setSimpleTaskDescription [_description, _displayName, _displayName];
_task setTaskState "Assigned";
player setCurrentTask _task;

[{ call (_this select 2) || { !([] call ULP_fnc_isOnTutorial) } }, [_stage, _task, _condition], {
	if !([] call ULP_fnc_isOnTutorial) exitWith {};

	_this params [ "_stage", "_task" ];

	_task setTaskState "Succeeded";
	player removeSimpleTask _task;

	private _nextStage = missionConfigFile >> "CfgTutorial" >> "Stages" >> getText (_stage >> "nextStage");

	if (!isClass _nextStage) exitWith {
		[] call ULP_fnc_finishTutorial;
	};

	[_nextStage] call ULP_fnc_triggerTutorialStage;
}] call ULP_fnc_waitUntilExecute;