/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getPerkRequirement";

_this params [
	["_perk", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPerks" >> _perk;
if !(isClass _cfg) exitWith { ["Doesn't Exist", 0] };

// Faction Check..
private _factions = getArray (_cfg >> "Requirements" >> "factions");
if !([player, _factions] call ULP_fnc_isFaction) exitWith {
	["Faction", _factions]
};

// Level Check...
private _level = getNumber (_cfg >> "Requirements" >> "level");
if (ULP_Level < _level) exitWith {
	["Level", _level]
};

// Prestige Check...
private _prestige = getNumber (_cfg >> "Requirements" >> "prestige");
if (ULP_Prestige < _prestige) exitWith {
	["Prestige", _prestige]
};

// Profession Check...
private _profession = getArray (_cfg >> "Requirements" >> "profession");
if ((count _profession) > 0 && { ULP_Prestige < (([_profession select 0] call ULP_fnc_getProfessionLevel) select 0) }) exitWith {
	_profession
};

// Empty Array? Success!
[]