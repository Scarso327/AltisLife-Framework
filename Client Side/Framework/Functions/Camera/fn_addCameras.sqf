/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addCameras";

_this params [
	["_screen", objNull, [objNull]],
	["_location", "", [""]]
];

private _cfg = missionConfigFile >> "CfgCameras" >> worldName >> _location;
if (isNull _screen || { !(isClass _cfg) }) exitWith { false };

{
	_screen addAction [
		format ["CCTV | %1", getText (_x >> "name")], { (_this select 3) call ULP_fnc_handleCamera }, [_screen, _location, configName _x], 7, true, true, "", format ["isNull (_this getVariable [""camera"", objNull]) && { %1 }", getText (_cfg >> "condition")], 5
	];
} forEach ("isClass _x" configClasses (_cfg >> "Cameras"));

_screen addAction ["CCTV | Turn Off ",  { (_this select 3) call ULP_fnc_handleCamera }, [_screen], 7, true, true, "", "!(isNull (_this getVariable [""camera"", objNull]))", 5];