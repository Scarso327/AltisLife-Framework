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

private _pos = getArray (_node >> "position");
private _radius = getNumber (_node >> "radius");

private _zone = createMarker [format ["redzone_%1_zone", _nodeName], _pos];
_zone setMarkerShape "Ellipse";
_zone setMarkerColor "ColorYellow";
_zone setMarkerSize [_radius, _radius];
_zone setMarkerBrush "FDIAGONAL";

private _marker = createMarker [_nodeName, _pos];
_marker setMarkerType getText (_nodeType >> "marker");
_marker setMarkerColor _nodeColour;
_marker setMarkerSize [0.5, 0.5];
_marker setMarkerText getText (_node >> "displayName");

private _nodeCfgName = configName _node;

private _obj = createSimpleObject ["A3\Weapons_f\empty.p3d", _pos, false];
_obj setVariable ["node", _nodeName];
_obj setVariable ["nodeCfgName", _nodeCfgName];
_obj setVariable ["location", _location];
_obj setVariable ["marker", _marker];
_obj setVariable ["area", _zone];
_obj setVariable ["score", getNumber (_nodeType >> "score"), true];

ULP_SRV_PvpConflictNodes set [_nodeName, _obj];
ULP_SRV_PvpConflictActiveLocations pushBackUnique _nodeCfgName;

["onConflictNodeSpawnedConflict", [_obj, _nodeName, _radius]] remoteExecCall ["ULP_fnc_invokeEvent", RANY, _nodeName];

true