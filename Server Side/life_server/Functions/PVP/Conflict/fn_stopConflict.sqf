/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_stopConflict";

{
	private _marker = _y getVariable ["marker", ""];
	private _zone = _y getVariable ["area", ""];

	deleteMarker _marker;
	deleteMarker _zone;
	deleteVehicle _y;

	remoteExecCall ["", _x]; // Remove JIP
} forEach ULP_SRV_PvpConflictNodes;

missionNamespace setVariable ["ULP_SRV_PvpConflictNodes", nil];
missionNamespace setVariable ["ULP_SRV_PvpConflictActiveLocations", nil];
missionNamespace setVariable ["ULP_SRV_PvpConflictTick", nil];
missionNamespace setVariable ["ULP_SRV_CurrentPvpMode", nil];

[ULP_SRV_PvpConflictEachFrameHandle] call ULP_fnc_removeEachFrame;
missionNamespace setVariable ["ULP_SRV_PvpConflictEachFrameHandle", nil];

private _winnerGroupId = -1; 
private _highest = 0;

{
	if (_y > _highest) then {
		_winnerGroupId = _x;
		_highest = _y;
	};
} forEach ULP_SRV_CurrentScores;

missionNamespace setVariable ["ULP_SRV_CurrentScores", nil];

private _winningGroup = [_winnerGroupId] call ULP_fnc_getGroupById;

["onStopConflict", [_winningGroup, _highest]] remoteExecCall ["ULP_fnc_invokeEvent", RANY];