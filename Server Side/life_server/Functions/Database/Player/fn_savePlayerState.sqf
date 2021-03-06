/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_savePlayerState";

_this params [
	["_player", objNull, [objNull]],
	["_state", 0, [0]],
	"_data"
];

private _steamid = getPlayerUID _player;
private _faction = [_player] call ULP_fnc_getFaction;

_faction = missionConfigFile >> "CfgFactions" >> _faction;
if (_steamid isEqualTo "" || { !(isClass (_faction)) }) exitWith {};

private _query = switch (_state) do {
	case 0: { format["%1licenses='%2'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data] call DB_fnc_mresArray] };
	case 1: { format["cash='%1'", [_data, ""] call ULP_fnc_numberText] };
	case 2: { format["bankacc='%1'", [_data, ""] call ULP_fnc_numberText] };
	default { "" };
};

if (_query isEqualTo "") exitWith {};

[format ["UPDATE players SET %1 WHERE pid='%2'", _query, _steamid], 1] call DB_fnc_asyncCall;