/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPopupCartelSpawn";

_this params [
	["_popupObj", objNull, [objNull]],
	["_radius", 250, [0]],
	["_message", "", [""]]
];

if (isNull _popupObj) exitWith {};

[_message] call ULP_fnc_hint;

private _trigger = createTrigger ["EmptyDetector", getPos _popupObj, false];
_trigger setTriggerArea [_radius, _radius, 0, false];
_trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];
_trigger setTriggerStatements ["this && { (vehicle player) in thisList }", "[""Entered Popup Cartel""] call ULP_fnc_hint", "[""Left Popup Cartel""] call ULP_fnc_hint"];

_popupObj setVariable ["trigger", _trigger];