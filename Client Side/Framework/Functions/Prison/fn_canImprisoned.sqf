/*
** Author: Jack "Scarso" Farhall
** Description: Returns if target _unit can be sent to prison...
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canImprisoned";

_this params [
	["_unit", player, [objNull]]
];

private _cfg = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;
if (isNull _unit || { !(isClass _cfg) }) exitWith { false };

isNumber (_cfg >> "imprisoned") && { [getNumber (_cfg >> "imprisoned")] call ULP_fnc_bool }