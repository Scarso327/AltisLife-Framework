/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_registerSession";

_this params [
	["_unit", objNull, [objNull]],
	["_uid", "", [""]],
	["_factionCfg", configNull, [configNull]]
];

if (isNull _unit || { _uid isEqualTo "" }) exitWith { false };

if (isNumber (_factionCfg >> "jointChannel") && { [getNumber(_factionCfg >> "jointChannel")] call ULP_fnc_bool }) then {
	["Joint", _unit] call ULP_SRV_fnc_addRadio;
};

private _session = createHashMap;
_session set ["SteamID", _uid];

_unit setVariable ["session", _session];
true