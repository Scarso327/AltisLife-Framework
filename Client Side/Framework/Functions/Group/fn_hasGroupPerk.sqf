/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasGroupPerk";

_this params [
	["_perk", "", [""]],
	["_group", group player, [grpNull]]
];

private _cfg = missionConfigFile >> "CfgGroups" >> "Types" >> (_group getVariable ["group_type", ""]) >> "Perks" >> _perk;
if (isNull _group || { !(isClass _cfg) }) exitWith { false };

(([_group] call ULP_fnc_groupLevel) >= getNumber (_cfg >> "level"));