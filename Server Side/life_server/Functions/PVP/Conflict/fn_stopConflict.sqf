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
missionNamespace setVariable ["ULP_SRV_PvpConflictTick", nil, true];

[ULP_SRV_PvpConflictEachFrameHandle] call ULP_fnc_removeEachFrame;
missionNamespace setVariable ["ULP_SRV_PvpConflictEachFrameHandle", nil];

["onConflictNodeCapturedConflict", ULP_SRV_PvpConflictNodeCaptureHandle] call ULP_fnc_removeEventHandler;
missionNamespace setVariable ["ULP_SRV_PvpConflictNodeCaptureHandle", nil];

private _winnerGroupId = -1; 

private _maxScore = getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "maxScore");
private _highestScore = 0;
private _sumScore = 0;

{
	_sumScore = _sumScore + _y;
	if (_y > _highestScore) then {
		_winnerGroupId = _x;
		_highestScore = _y;
	};
} forEach ULP_SRV_CurrentScores;

private _winningGroup = [_winnerGroupId] call ULP_fnc_getGroupById;

private _baseReward = getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "baseReward");
private _multipliedReward = getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "multipliedReward");

private _reward = _baseReward + (_multipliedReward * _sumScore * _highestScore / _maxScore);

if !(isNull _winningGroup) then {
	[_winnerGroupId, _reward, true] call ULP_SRV_fnc_updateGroupFunds;

	{
		[_winningGroup, configName _x, 0.05] call ULP_SRV_fnc_addGroupBuff;
	} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgGroups" >> "Buffs"));
};

["onStopConflict", [_winningGroup, _highestScore, _reward]] remoteExecCall ["ULP_fnc_invokeEvent", RANY];