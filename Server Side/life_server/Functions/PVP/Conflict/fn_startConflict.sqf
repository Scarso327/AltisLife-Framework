/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startConflict";

private _location = _this;

["onStartConflict", [_location]] remoteExecCall ["ULP_fnc_invokeEvent", RANY];

ULP_SRV_PvpConflictNodes = createHashMap;
ULP_SRV_PvpConflictActiveLocations = [];

for "_i" from 0 to 2 do {
	[format["ConflictNode%1", _i], _location] call ULP_SRV_fnc_spawnConflictNode;
};

missionNamespace setVariable ["ULP_SRV_PvpConflictStartTime", serverTime];
missionNamespace setVariable ["ULP_SRV_PvpConflictTick", serverTime + getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "tickDuration"), true];

ULP_SRV_PvpConflictEachFrameHandle = ([[], { [] call ULP_SRV_fnc_onEachFrameConflict; }] call ULP_fnc_addEachFrame);