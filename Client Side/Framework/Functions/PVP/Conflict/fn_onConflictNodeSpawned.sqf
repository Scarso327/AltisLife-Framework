/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onConflictNodeSpawned";

if !(hasInterface) exitWith {};

_this params [
	["_obj", objNull, [objNull]],
	["_nodeName", "", [""]],
	["_radius", 200, [0]]
];

if (isNull _obj || { _nodeName isEqualTo "" }) exitWith {};

private _trigger = createTrigger ["EmptyDetector", getPos _obj, false];
_trigger setVariable ["zoneObject", _obj];
_trigger setVariable ["zoneName", _nodeName];

_trigger setTriggerArea [_radius, _radius, 0, false];
_trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];
_trigger setTriggerStatements ["this && { (vehicle player) in thisList }", "[thisTrigger getVariable ""zoneObject"", thisTrigger getVariable ""zoneName""] call ULP_fnc_zoneCapture;", "[thisTrigger getVariable ""zoneObject"", thisTrigger getVariable ""zoneName"", 1] call ULP_fnc_zoneCapture;"];

_obj setVariable ["trigger", _trigger];
_obj setVariable ["isConflictZone", true];
_obj setVariable ["hasPlayerTags", true];
_obj setVariable ["name", _nodeName];

[{ isNull (_this select 0) }, [_obj, _trigger], { deleteVehicle (_this select 1); }] call ULP_fnc_waitUntilExecute;