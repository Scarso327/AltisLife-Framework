/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeZoneCaptureEachFrame";

_this params [
	["_zoneName", "", [""]]
];

private _handle = ULP_ZoneCaptureEachFrameHandles getOrDefault [_zoneName, -1];
if (_handle isEqualTo -1) exitWith {};

[_handle] call ULP_fnc_removeEachFrame;
ULP_ZoneCaptureEachFrameHandles deleteAt _zoneName;