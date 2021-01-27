/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initSurvival";

{
	[(configName _x)] call ULP_fnc_onSurvival;
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgSurvival"));