/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_unregisterSession";

_this params [
	["_unit", objNull, [objNull]]
];

private _uid = getPlayerUID _unit;

private _session = _unit getVariable "session";
if (isNil "_session" || { !((_session getOrDefault ["SteamID", ""]) isEqualTo _uid) }) exitWith {};

private _factionCfg = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;
if (isNumber (_factionCfg >> "jointChannel") && { [getNumber(_factionCfg >> "jointChannel")] call ULP_fnc_bool }) then {
	["Joint", _unit] call ULP_SRV_removeRadio;
};

_unit setVariable ["session", nil];
[format ["Unregistered %1", _uid]] call ULP_fnc_logIt;