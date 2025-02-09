/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_savePlayerInfo";

_this params [
	["_unit", objNull, [objNull]],
	["_cash", 0, [0]],
	["_bank", 0, [0]],
	["_gear", [], [[]]],
	["_licenses", [], [[]]],
	["_stats", [], [[]]]
];

if (isNull _unit) exitWith {};

private _name = name _unit;
private _steamid = getPlayerUID _unit;
private _faction = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;

private _session = _unit getVariable "session";
if (isNil "_session" || { !((_session getOrDefault ["SteamID", ""]) isEqualTo _steamid) }) exitWith {
	[format ["Failed to savePlayerInfo for %1, requested %2", _steamid, _this]] call ULP_fnc_logIt;
};

if !(isClass _faction) exitWith {};

if !([_unit, [_unit, "Cash"] call ULP_SRV_fnc_getSessionField, _cash] call ULP_SRV_fnc_validateField) exitWith {};
if !([_unit, [_unit, "Bank"] call ULP_SRV_fnc_getSessionField, _bank] call ULP_SRV_fnc_validateField) exitWith {};

// We don't sync all session vars as stuff like cash and money should be saved when used to avoid expliots
[_unit, "Gear", _gear] call ULP_SRV_fnc_setSessionField;

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
		"UPDATE `players` SET `name`='%2', `cash`='%3', `bankacc`='%4', `%1gear`='%5', `%1licenses`='%6', `%1stats`='%7', `playtime`='%8' WHERE `pid`='%9'",
		getText(_faction >> "DatabaseInfo" >> "queryPrefix"), _name, _cash, _bank, _gear, _licenses, _stats, _playtime, _steamid
	], 1
] call DB_fnc_asyncCall;