/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canPrestige";

private _professionsMaxed = true;

{
	scopeName "fn_canPrestige_profLoop";

	([configName _x] call ULP_fnc_getProfessionLevel) params ["_level", "_points"];

	private _requirement = getNumber (_x >> "xpLevel");

	if !(_level isEqualTo getNumber (_x >> "maxLevel") && { _points isEqualTo _requirement }) exitWith {
		_professionsMaxed = false;
	};
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgProgression" >> "CfgProfessions"));

(ULP_Level isEqualTo ([] call ULP_fnc_getMaxLevel) && // Max Level
{ ULP_XP isEqualTo ([ULP_Level] call ULP_fnc_getRequiredXP) } && // Max XP
{ _professionsMaxed })