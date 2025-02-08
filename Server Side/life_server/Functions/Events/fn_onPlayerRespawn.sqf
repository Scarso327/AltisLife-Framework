/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onPlayerRespawn";

_this params [
	["_unit", objNull, [objNull]],
	["_corpse", objNull, [objNull]]
];

if !(isPlayer _unit) exitWith {};

private _cfg = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;

if !(isClass _cfg) exitWith {};

if (isNumber (_cfg >> "jointChannel") && { [getNumber(_cfg >> "jointChannel")] call ULP_fnc_bool }) then {
	["Joint", _corpse] call ULP_SRV_fnc_removeRadio;
	["Joint", _unit] call ULP_SRV_fnc_addRadio;
};