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
private _scores = + ULP_SRV_CurrentScores;
private _end = false;
private _doesNotThreaten = getArray (missionConfigFile >> "CfgSettings" >> "doesntThreaten");

{
	private _area = _y getVariable ["area", ""];

	private _winner = _y getVariable ["object_owner", grpNull];
	private _groupId = [_winner] call ULP_fnc_groupId;

	private _groupsInZone = (([_area, allPlayers, ["Civilian"], { !((currentWeapon _this) in _doesNotThreaten) }] call ULP_fnc_unitsInZone) apply {
		group _x
	});

	if (!isNull _winner && { !(_groupId isEqualTo -1) } && { (count (_groupsInZone arrayIntersect _groupsInZone)) <= 1 }) then {
		private _zoneScore = _y getVariable ["score", 0];
		private _scoreChange = 100 min _zoneScore;

		private _newScore = _zoneScore - _scoreChange;
		if (_newScore > 0) then {
			_y setVariable ["score", _newScore, true];
		} else {
			private _location = _y getVariable ["location", configNull];
			private _node = _y getVariable ["nodeCfg", configNull];
			private _nodeName = configName _node;
			private _marker = _y getVariable ["marker", ""];

			deleteMarker _marker;
			deleteMarker _area;
			deleteVehicle _y;

			remoteExecCall ["", _x];

			ULP_SRV_PvpConflictNodes deleteAt _x;

			private _nextNode = [_x, _location] call ULP_SRV_fnc_spawnConflictNode;

			["onConflictNodeDepletedConflict", [_node, _nextNode]] remoteExecCall ["ULP_fnc_invokeEvent", RANY];

			// Only remove after spawning to ensure we don't respawn the same point
			ULP_SRV_PvpConflictActiveLocations = ULP_SRV_PvpConflictActiveLocations - [_nodeName];
		};

		private _score = _scores getOrDefault [_groupId, 0];
		_score = (_score + _scoreChange) min _maxScore;

		_scores set [_groupId, _score];

		_end = (_end || { _score isEqualTo _maxScore });
	};
} forEach _nodes;

missionNamespace setVariable ["ULP_SRV_CurrentScores", _scores, true];
if (_end) exitWith {
	[] call ULP_SRV_fnc_stopConflict;
};

missionNamespace setVariable ["ULP_SRV_PvpConflictTick", serverTime + getNumber (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "tickDuration"), true];