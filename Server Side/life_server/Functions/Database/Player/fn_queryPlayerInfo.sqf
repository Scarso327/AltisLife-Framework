/*
** Author: Jack "Scarso" Farhall
** Description: Asks the server to provide us with our information...
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_queryPlayerInfo";

_this params [
	["_unit", objNull, [objNull]]
];

if (_unit isEqualTo objNull) exitWith {};

private _uid = getPlayerUID _unit;
private _factionCfg = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;
if !(isClass _factionCfg) exitWith {};

private _query = [
	format["SELECT `uid`, `pid`, `group_id`, `cash`, `bankacc`, `%1playtime`, `insert_time`, `adminlevel`, `eventslevel`, `donorlevel`, `%1licenses`, `%1gear`, `%1stats`, `professions`, `prestige`, `level`, `xp`, `achievements`, `%1daily_tasks`, `%1weekly_tasks`, `textures`, `titles`, `%1perks`, `reputation`, `blueprints`, `%1wounded`", getText(_factionCfg >> "DatabaseInfo" >> "queryPrefix")],
	getText(_factionCfg >> "DatabaseInfo" >> "customQuery"),
	format["FROM `players` WHERE `pid`='%1'", _uid]
];

_query = _query joinString " ";

private _attempts = _unit getVariable ["queryAttempts", 0];
if (_attempts >= 3) exitWith {
	["Failed to query player data after attempts"] call ULP_fnc_logIt;
	["PlayerInformationQueryFailed", []] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

private _playerData = false;
private _result = [_query, 2] call DB_fnc_asyncCall;

if (_result isEqualType "" || { _result isEqualTo [] }) exitWith {
	[_unit, { _this call ULP_SRV_fnc_queryPlayerInfo }] call ULP_SRV_fnc_insertPlayerInfo;

	_attempts = _attempts + 1;
	_unit setVariable ["queryAttempts", _attempts];
};

// Player save found, time to convert data types etc...
private _newResult = _result;

// Licenses, Gear, Stats, Professions, Achievements, Daily Tasks, Weekly Tasks, Textures, Titles, Perks, Blueprints
private _arraysToConvert = [10, 11, 12, 13, 17, 18, 19, 20, 21, 22, 24];
private _factionArrays = getArray (_factionCfg >> "DatabaseInfo" >> "arrayIndexes");
if !(_factionArrays isEqualTo []) then { _arraysToConvert append _factionArrays; };

// Professions, Daily Tasks, Weekly Tasks, Textures, Perks, Blueprints
private _hashmapsToCreate = [13, 18, 19, 20, 22, 24];
private _factionMaps = getArray (_factionCfg >> "DatabaseInfo" >> "mapIndexes");
if !(_factionMaps isEqualTo []) then { _arraysToConvert append _factionMaps; };

// Wounded Status, (Blacklist / Arrest Status)
private _boolsToConvert = [25, 26];
private _factionBools = getArray (_factionCfg >> "DatabaseInfo" >> "boolIndexes");
if !(_factionBools isEqualTo []) then { _arraysToConvert append _factionBools; };

// Coverts data types to something arma can understand...
{ _newResult set [_x, [(_result select _x)] call DB_fnc_mresToArray] } forEach _arraysToConvert;
{ _newResult set [_x, [(_result select _x), 1] call ULP_fnc_bool] } forEach _boolsToConvert;
{ _newResult set [_x, createHashMapFromArray (_newResult select _x)]; } forEach _hashmapsToCreate;

// Groups + Housing
private _group = [_unit, _result select 2, _factionCfg] call ULP_SRV_fnc_queryGroupInfo;
_newResult pushBack _group;
_newResult pushBack ([_unit, _factionCfg, _group] call ULP_SRV_fnc_getHouses);

// Misc
_newResult pushBack (missionNamespace getVariable [format ["%1_KEYS_%2", _uid, (side _unit)], []]);
_newResult pushBack (_unit getVariable ["isFirstInsert", false]);
_newResult pushBack ULP_SRV_Date; // Include date from serer here...

_playerData = _newResult;

// If session registration fails then return nothing...
if !([_unit, _uid, _factionCfg, _playerData] call ULP_SRV_fnc_registerSession) then {
	_playerData = [];
};

if (_playerData isEqualType []) exitWith {
	[_playerData] remoteExecCall ["ULP_fnc_setPlayerInfo", _unit];
};

// Fail...
[format ["Failed to query player data for %1, got back %2", _uid, _playerData]] call ULP_fnc_logIt;
["PlayerInformationQueryFailed", []] remoteExecCall ["ULP_fnc_invokeEvent", _unit];