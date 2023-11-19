/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_registerSession";

_this params [
	["_unit", objNull, [objNull]],
	["_uid", "", [""]],
	["_factionCfg", configNull, [configNull]],
	["_playerData", [], [[]]]
];

if (isNull _unit || { _uid isEqualTo "" }) exitWith { false };

if (isNumber (_factionCfg >> "jointChannel") && { [getNumber(_factionCfg >> "jointChannel")] call ULP_fnc_bool }) then {
	["Joint", _unit] call ULP_SRV_fnc_addRadio;
};

_playerData params ["", "", "", "_cash", "_bank", "", "", "_adminlevel", "", "", "", "", "", "_prestige", "_level", "_xp", "", "", "", "", "", "_perks"];

private _session = createHashMap;
_session set ["SteamID", _uid];
_session set ["Cash", _cash];
_session set ["Bank", _bank];
_session set ["Prestige", _prestige];
_session set ["Level", _level];
_session set ["XP", _xp];
_session set ["Perks", _perks];

_unit setVariable ["session", _session];
_unit setVariable ["reputation", _playerData select 23];

if (_adminlevel > 0) then {
	_unit setVariable ["srv_is_admin", true];
};

[format ["Registered %1", _uid]] call ULP_fnc_logIt;
true