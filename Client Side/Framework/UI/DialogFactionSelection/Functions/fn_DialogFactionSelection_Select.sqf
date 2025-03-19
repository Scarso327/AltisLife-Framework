/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogFactionSelection_Select";

_this params [ "_button" ];

private _display = _button getVariable ["display", displayNull];
if (isNull _button || { isNull _display }) exitWith {};

disableSerialization;

private _faction = _button getVariable ["faction", ""];
private _cfg = missionConfigFile >> "CfgFactions" >> _faction;

private _online = [[_faction]] call ULP_fnc_onlineFaction;
if (isNumber (_cfg >> "limit") && { _online >= getNumber (_cfg >> "limit") }) exitWith {
	[format ["This faction is at it's max allowable players with %1 online", _online]] call ULP_fnc_hint;
};

_display closeDisplay 2;

[player, _faction] call ULP_fnc_setFaction;