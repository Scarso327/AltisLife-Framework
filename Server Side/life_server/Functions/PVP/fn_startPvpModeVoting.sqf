/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startPvpModeVoting";

if !(isNil "ULP_SRV_PvpModes") exitWith {
	["PVP Mode vote start failed because one is already active..."] call ULP_fnc_logIt;
};

if !(isNil "ULP_SRV_CurrentPvpMode") exitWith {
	["PVP Mode vote start failed because a mode is already active..."] call ULP_fnc_logIt;
};

private _modes = [];

private _possibleModes = ("isClass _x" configClasses (missionConfigFile >> "CfgPvpModes" >> "Modes")) apply {
	[_x, ("isClass _x" configClasses (_x >> "Locations" >> worldName))]
};

for "_i" from 0 to 2 do {
	if (_possibleModes isEqualTo []) exitWith {};

	private _mode = selectRandom (_possibleModes select { (count (_x select 1)) > 0  });
	private _index = _possibleModes find _mode;

	private _locations = _mode select 1;

	private _location = selectRandom _locations;
	_locations = _locations - [_location];

	_modes pushBackUnique [_mode select 0, _location];

	if (_locations isEqualTo []) then {
		_possibleModes deleteAt _index;
	} else {
		_possibleModes set [_index, _mode];
	};
};

if (_modes isEqualTo []) exitWith {
	["PVP Mode vote failed as no modes were found..."] call ULP_fnc_logIt;
};

ULP_SRV_PvpModes = createHashMapFromArray (_modes apply { [format["%1%2", configName (_x select 0), configName (_x select 1)], _x] });
ULP_SRV_PvpVotes = createHashMap;

missionNamespace setVariable ["ULP_PvpMode_VoteStartTime", serverTime, true];
["PvpVoteStarted", [_modes]] remoteExecCall ["ULP_fnc_invokeEvent", RANY, "PvpVoteStarted"];

[getNumber (missionConfigFile >> "CfgPvpModes" >> "voteDuration"), [], { [] call ULP_SRV_fnc_finishPvpModeVoting; }] call ULP_fnc_waitExecute;