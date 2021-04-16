/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hasBlueprint";

_this params [
	["_type", "", [""]],
	["_blueprint", "", [""]]
];

if !(isClass (missionConfigFile >> "CfgBlueprints" >> _type >> _blueprint)) exitWith { false };

(_blueprint in (ULP_Blueprints getOrDefault [_type, []]))