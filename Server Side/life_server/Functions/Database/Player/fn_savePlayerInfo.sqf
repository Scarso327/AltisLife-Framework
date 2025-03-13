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

private _playtime = _unit getVariable ["playTime", 0];
private _timePlayed = round ((time - (_unit getVariable ["joinTime", 0])) / 60);

private _newPlayTime = _playtime + _timePlayed;

[
	format [
		"UPDATE `players` SET `name`='%2', `cash`='%3', `bankacc`='%4', `%1gear`='%5', `%1licenses`='%6', `%1stats`='%7', `%1playtime`='%8' WHERE `pid`='%9'",
		getText(_faction >> "DatabaseInfo" >> "queryPrefix"), _name, _cash, _bank, _gear, _licenses, _stats, _newPlayTime, _steamid
	], 1
] call DB_fnc_asyncCall;