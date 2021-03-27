/*
** Author: Jack "Scarso" Farhall
** Description: Asks the server to provide us with our information...
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_queryPlayerInfo";

_this params [
	["_unit", objNull, [objNull]]
];

if (_unit isEqualTo objNull) exitWith {
	// Fail...
};

private _uid = getPlayerUID _unit;
private _factionCfg = missionConfigFile >> "CfgFactions" >> [_unit] call ULP_fnc_getFaction;
private _playTimeIndex = getNumber(_factionCfg >> "DatabaseInfo" >> "timeIndex");

private _query = [
	format["SELECT uid, pid, group_id, cash, bankacc, playtime, insert_time, adminlevel, eventslevel, donorlevel, %1licenses, %1gear, %1stats, professions, prestige, level, xp, achievements, daily_tasks, weekly_tasks, textures", getText(_factionCfg >> "DatabaseInfo" >> "queryPrefix")],
	getText(_factionCfg >> "DatabaseInfo" >> "customQuery"),
	format["FROM players WHERE pid='%1'", _uid]
];

_query = _query joinString " ";

private _playerData = false;
private _firstInsert = false;
private _attempts = 0;

for "_i" from 0 to 1 step 0 do {
	if (_playerData isEqualType [] || { _attempts > 3 }) exitWith {};

	private _result = [_query, 2] call DB_fnc_asyncCall;

	if (_result isEqualType "" || { _result isEqualTo [] }) then {
		// We don't have a player save active at this time, need to insert it...

		private _name = name _unit;

		[
			format ["INSERT INTO players (pid, name, cash, bankacc, aliases, cop_licenses, med_licenses, civ_licenses, civ_gear, cop_gear, med_gear, professions, hato_licenses, hato_gear, achievements, daily_tasks, weekly_tasks, textures) VALUES('%1', '%2', '0', '%3', '%4','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""','""[]""')",
				_uid,
				[_name] call DB_fnc_mresString,
				[LIFE_SETTINGS(getNumber,"starting_bank"), ""] call ULP_fnc_numberText,
				[[_name]] call DB_fnc_mresArray
			], 1
		] call DB_fnc_asyncCall;

		uiSleep 3; // Wait to ensure the request has a chance to finish...

		_firstInsert = true;
	} else {
		// Player save found, time to convert data types etc...
		private _newResult = _result;

		// Playtime, Licenses, Gear, Stats, Professions, Achievements, Daily Tasks, Weekly Tasks, Textures
		private _arraysToConvert = [5, 10, 11, 12, 13, 17, 18, 19, 20];

		// Professions, Daily Tasks, Weekly Tasks, Textures
		private _hashmapsToCreate = [13, 18, 19, 20];

		// (Blacklist / Arrest Status)
		private _boolsToConvert = [21];

		// Coverts data types to something arma can understand...
		{ _newResult set [_x, [(_result select _x)] call DB_fnc_mresToArray] } forEach _arraysToConvert;
		{ _newResult set [_x, [(_result select _x), 1] call ULP_fnc_bool] } forEach _boolsToConvert;
		{ _newResult set [_x, createHashMapFromArray (_newResult select _x)]; } forEach _hashmapsToCreate;

		// Setup playtime tracking...
		private _playtime = _newResult select 5;
        private _index = TON_fnc_playtime_values_request find [_uid, _playtime];

        if !(_index isEqualTo -1) then {
            TON_fnc_playtime_values_request set[_index, -1];
            TON_fnc_playtime_values_request = TON_fnc_playtime_values_request - [-1];
            TON_fnc_playtime_values_request pushBack [_uid, _playtime];
        } else {
            TON_fnc_playtime_values_request pushBack [_uid, _playtime];
        };

        [_uid, (_playtime select _playTimeIndex)] call TON_fnc_setPlayTime;

		// Groups + Housing
		_newResult pushBack ([_unit, _result select 2, _factionCfg] call ULP_SRV_fnc_queryGroupInfo);
		_newResult pushBack false;

		// Misc
		_newResult pushBack (missionNamespace getVariable [format ["%1_KEYS_%2", _uid, (side _unit)], []]);
		_newResult pushBack _firstInsert;
		_newResult pushBack ULP_SRV_Date; // Include date from serer here...

		_playerData = _newResult;

		// If session registration fails then return nothing...
		if !([_unit, _uid, _factionCfg, _playerData] call ULP_SRV_fnc_registerSession) then {
			_playerData = [];
		};
	};
	
	_attempts = _attempts + 1;
};

if (_playerData isEqualType []) exitWith {
	[_playerData] remoteExecCall ["ULP_fnc_setPlayerInfo", remoteExecutedOwner];
};

// Fail...