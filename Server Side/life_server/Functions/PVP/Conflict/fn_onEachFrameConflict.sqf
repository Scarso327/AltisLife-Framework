/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onEachFrameConflict";

if (isNil "ULP_SRV_PvpConflictNodes" || { ULP_SRV_PvpConflictNodes isEqualTo createHashMap }) exitWith {
	[_thisEventHandler] call ULP_fnc_removeEachFrame;
};

private _tickTime = missionNamespace getVariable ["ULP_SRV_PvpConflictTick", serverTime];
if (_tickTime > serverTime) exitWith {};

private _maxScore = getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "maxScore");
private _nodes = + ULP_SRV_PvpConflictNodes;
private _end = false;

{
	private _winner = _y getVariable ["object_owner", grpNull];
	private _groupId = [_winner] call ULP_fnc_groupId;

	if !(isNull _winner && { _groupId isEqualTo -1 }) then {
		private _zoneScore = _y getVariable ["score", 0];
		private _scoreChange = 100 min _zoneScore;

		private _newScore = _zoneScore - _scoreChange;
		if (_newScore > 0) then {
			_y setVariable ["score", _newScore, true];
		} else {
			private _location = _y getVariable ["location", configNull];
			private _node = _y getVariable ["nodeCfgName", ""];
			private _marker = _y getVariable ["marker", ""];
			private _zone = _y getVariable ["area", ""];

			deleteMarker _marker;
			deleteMarker _zone;
			deleteVehicle _y;

			remoteExecCall ["", _x];

			ULP_SRV_PvpConflictNodes deleteAt _x;

			[_x, _location] call ULP_SRV_fnc_spawnConflictNode;

			// Only remove after spawning to ensure we don't respawn the same point
			ULP_SRV_PvpConflictActiveLocations = ULP_SRV_PvpConflictActiveLocations - [_node];
		};

		private _score = ULP_SRV_CurrentScores getOrDefault [_groupId, 0];
		_score = (_score + _scoreChange) min _maxScore;

		ULP_SRV_CurrentScores set [_groupId, _score];

		_end = _score isEqualTo _maxScore;
	};

	if (_end) exitWith { [] call ULP_SRV_fnc_stopConflict; };
} forEach _nodes;

missionNamespace setVariable ["ULP_SRV_PvpConflictTick", serverTime + getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "tickDuration")];