/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_buildEventNotification";

_this params [
	["_object", objNull, [objNull]],
	["_name", "Something", [""]]
];

private _cfg = configFile >> "CfgPatches" >> "ULPServer" >> "CfgNotifications" >> _name;
if (isNull _object || { !isClass _cfg }) exitWith {};

private _location = [_object] call ULP_fnc_getNearestLocation;
private _compass = [_location, _object] call ULP_fnc_getCompassDir;

private _displayName = getText (_cfg >> "displayName");

[
	_displayName, 
	format [getText (_cfg >> "message"), _displayName, format [_compass, text _location]], 
	getText (_cfg >> "colour"), 
	getText (_cfg >> "image")
] call ULP_SRV_fnc_sendNotification;