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

private _modes = ("isClass _x" configClasses (missionConfigFile >> "CfgPvpModes" >> "Modes")) apply {
    private _mode = _x;

    (("isClass _x" configClasses (_mode >> "Locations" >> worldName)) apply {
        [_mode, _x]
    })
};

_modes = _modes select 0;

if (_modes isEqualTo []) exitWith {
    ["PVP Mode vote failed as no modes were found..."] call ULP_fnc_logIt;
};

ULP_SRV_PvpModes = createHashMapFromArray (_modes apply { [format["%1%2", configName (_x select 0), configName (_x select 1)], _x] });
ULP_SRV_PvpVotes = createHashMap;

missionNamespace setVariable ["ULP_PvpMode_VoteStartTime", serverTime, true];
["PvpVoteStarted", [_modes]] remoteExecCall ["ULP_fnc_invokeEvent", RANY, "PvpVoteStarted"];

[getNumber (missionConfigFile >> "CfgPvpModes" >> "voteDuration"), [], { [] call ULP_SRV_fnc_finishPvpModeVoting; }] call ULP_fnc_waitExecute;