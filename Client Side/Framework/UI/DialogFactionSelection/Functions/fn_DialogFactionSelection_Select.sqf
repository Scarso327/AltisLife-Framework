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

_display closeDisplay 2;

private _faction = _button getVariable ["faction", ""];
[player, _faction] call ULP_fnc_setFaction;