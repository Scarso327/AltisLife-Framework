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

// If they were downed wipe their gear
if (isDowned(_unit)) then {
	private _cash = [_unit, "Cash"] call ULP_SRV_fnc_getSessionField;

	[_unit, 1, [0, _cash, false, "Disconnected while dead"]] call ULP_SRV_fnc_savePlayerState; // Remove Cash
	[_unit, 15, []] call ULP_SRV_fnc_savePlayerState; // Remove Gear
};

_unit setVariable ["session", nil];
_unit setVariable ["reputation", nil];

[format ["Unregistered %1", _uid]] call ULP_fnc_logIt;