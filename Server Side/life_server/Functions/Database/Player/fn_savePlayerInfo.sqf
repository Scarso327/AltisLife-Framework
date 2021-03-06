/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_savePlayerInfo";

_this params [
	["_name", "", [""]],
	["_steamid", "", [""]],
	["_faction", "", [""]],
	["_cash", 0, [0]],
	["_bank", 0, [0]],
	["_gear", [], [[]]],
	["_licenses", [], [[]]],
	["_stats", [], [[]]]
];

_faction = missionConfigFile >> "CfgFactions" >> _faction;

if (_name isEqualTo "" || { _steamid isEqualTo "" } || { !(isClass (_faction)) }) exitWith {};

_name = [_name] call DB_fnc_mresString;
_cash = [_cash, ""] call ULP_fnc_numberText;
_bank = [_bank, ""] call ULP_fnc_numberText;
_gear = [_gear] call DB_fnc_mresArray;
_licenses = [_licenses] call DB_fnc_mresArray;
_stats = [_stats] call DB_fnc_mresArray;

private _playtime = [];
private _timeIndex = (TON_fnc_playtime_values_request findIf { (_x select 0) isEqualTo _steamid });

if (_timeIndex > -1) then {
	_playtime = (TON_fnc_playtime_values_request select _timeIndex) select 1;
	_playtime set[getNumber(_faction >> "DatabaseInfo" >> "timeIndex"), [_steamid] call TON_fnc_getPlayTime];
};

_playtime = [_playtime] call DB_fnc_mresArray;

[
	format [
		"UPDATE players SET name='%2', cash='%3', bankacc='%4', %1gear='%5', %1licenses='%6', %1stats='%7', playtime='%8' WHERE pid='%9'",
		getText(_faction >> "DatabaseInfo" >> "queryPrefix"), _name, _cash, _bank, _gear, _licenses, _stats, _playtime, _steamid
	], 1
] call DB_fnc_asyncCall;