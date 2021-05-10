/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_unlockBlueprint";

_this params [
	["_type", "", [""]],
	["_blueprint", "", [""]]
];

private _cfg = missionConfigFile >> "CfgBlueprints" >> _type >> _blueprint;
if !(isClass _cfg) exitWith { false };

if (_this call ULP_fnc_hasBlueprint) exitWith { false };

[format ["You've unlocked the blueprint <t color='#B92DE0'>%1</t>", getText (_cfg >> "displayName")]] call ULP_fnc_hint;

private _blueprints = (ULP_Blueprints getOrDefault [_type, []]);
_blueprints pushBackUnique _blueprint;

ULP_Blueprints set [_type, _blueprints];
[player, 14, ULP_Blueprints] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

true