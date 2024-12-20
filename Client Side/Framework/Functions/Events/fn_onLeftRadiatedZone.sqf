/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onLeftRadiatedZone";

_this params [
	["_thisTrigger", objNull, [objNull]]
];

private _isRadiated = missionNamespace getVariable "ULP_Radiated";
if (isNull _thisTrigger || { isNil "_isRadiated" }) exitWith {};

[_isRadiated] call ULP_fnc_removeEachFrame;
missionNamespace setVariable ["ULP_Radiated", nil];

["LeftRadiatedZone", []] call ULP_fnc_invokeEvent;