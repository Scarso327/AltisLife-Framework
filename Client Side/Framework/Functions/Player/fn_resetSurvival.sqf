/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_resetSurvival";

{
	missionNamespace setVariable [(configName _x), getNumber(_x >> "max")];
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgSurvival"));