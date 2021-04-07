/*
** Author: Jack "Scarso" Farhall
** Description: Returns if target _unit can imprison someone...
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canImprison";

_this params [
	["_unit", player, [objNull]]
];

private _cfg = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;
if (isNull _unit || { !(isClass _cfg) }) exitWith { false };

isNumber (_cfg >> "imprison") && { [getNumber (_cfg >> "imprison")] call ULP_fnc_bool } && {
	(player distance (getMarkerPos (getText (missionConfigFile >> "CfgPrison" >> worldName >> "marker")))) <= 50
}