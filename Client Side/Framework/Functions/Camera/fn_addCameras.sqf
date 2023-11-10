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
		format ["CCTV | %1", getText (_x >> "name")], { (_this select 3) call ULP_fnc_handleCamera }, [_screen, _location, configName _x], 7, true, true, "", format ["isNull (_target getVariable [""camera"", objNull]) && { %1 }", getText (_cfg >> "condition")], 5
	];
} forEach ("isClass _x" configClasses (_cfg >> "Cameras"));

// Stop spam of "off" buttons
if (isNil { _screen getVariable "has_off_button" }) then {
	_screen addAction ["CCTV | Turn Off ",  { (_this select 3) call ULP_fnc_handleCamera }, [_screen], 7, true, true, 
		"", "!(isNull (_target getVariable [""camera"", objNull]))", 5];

	_screen setVariable ["has_off_button", true];
};