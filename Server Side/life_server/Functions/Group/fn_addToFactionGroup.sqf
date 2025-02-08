/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addToFactionGroup";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit) exitWith {};

private _faction = [_unit] call ULP_fnc_getFaction;

private _group = ULP_FactionGroups getOrDefault [_faction, grpNull];

if (isNull _group) then {
	_group = createGroup [side _unit, false];
	_group setGroupIdGlobal [getText (missionConfigFile >> "CfgFactions" >> _faction >> "shortName")];

	ULP_FactionGroups set [_faction, _group];
};

[_unit] joinSilent _group;