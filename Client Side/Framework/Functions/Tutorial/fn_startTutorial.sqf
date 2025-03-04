/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_startTutorial";

if !([] call ULP_fnc_isHobo) exitWith {
	["You don't meet the requirements to do the tutorial"] call ULP_fnc_hint;
	false
};

if ([] call ULP_fnc_isOnTutorial) exitWith {
	["You're already doing the tutorial and can't stat it again"] call ULP_fnc_hint;
	false
};

private _firstStage = (configProperties [missionConfigFile >> "CfgTutorial" >> "Stages", "isClass _x && { !(call compile getText (_x >> ""condition"")) }", true]) param [0, configNull];

if (isNull _firstStage) exitWith {
	["You've already met all requirements for the tutorial"] call ULP_fnc_hint;
	false
};

player setVariable ["isOnTutorial", true, true];

[_firstStage] call ULP_fnc_triggerTutorialStage;