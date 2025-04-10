/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addZoneCaptureEachFrame";

_this params [
	["_zoneName", "", [""]],
	["_handle", -1, [0]]
];

if (_zoneName isEqualTo "" || { _handle isEqualTo -1 }) exitWith { false };

if (_zoneName in ULP_ZoneCaptureEachFrameHandles) then { [_zoneName] call ULP_fnc_removeZoneCaptureEachFrame; };

ULP_ZoneCaptureEachFrameHandles set [_zoneName, _handle];

true