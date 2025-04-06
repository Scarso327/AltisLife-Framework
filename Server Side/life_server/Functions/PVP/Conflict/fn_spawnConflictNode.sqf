/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_spawnConflictNode";

_this params [
	["_nodeName", "", [""]],
	["_location", configNull, [configNull]]
];

private _node = selectRandom ("isClass _x && { !((configName _x) in ULP_SRV_PvpConflictActiveLocations) }" configClasses (_location >> "Nodes"));
if (isNil "_node" || { _nodeName in ULP_SRV_PvpConflictNodes }) exitWith { false };

private _nodeColour = getText (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "markerColour");
private _nodeType = selectRandom ("isClass _x" configClasses (missionConfigFile >> "CfgPvpModes" >> "Modes" >> "Conflict" >> "NodeTypes"));

private _marker = createMarker [_nodeName, getArray (_node >> "position")];
_marker setMarkerType getText (_nodeType >> "marker");
_marker setMarkerColor _nodeColour;
_marker setMarkerSize [0.5, 0.5];
_marker setMarkerText getText (_node >> "displayName");

private _obj = createSimpleObject ["A3\Weapons_f\empty.p3d", [0, 0, 0], false];
_obj setVariable ["node", _nodeName];
_obj setVariable ["location", _location];
_obj setVariable ["marker", _marker];
_obj setVariable ["score", getNumber (_nodeType >> "score"), true];

ULP_SRV_PvpConflictNodes set [_nodeName, _obj];
ULP_SRV_PvpConflictActiveLocations pushBackUnique (configName _node);

["onConflictNodeSpawnedConflict", [_obj, _nodeName]] remoteExecCall ["ULP_fnc_invokeEvent", RANY, _nodeName];

true