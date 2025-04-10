/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onPopupCartelSpawn";

if !(hasInterface) exitWith {};

_this params [
	["_obj", objNull, [objNull]],
	["_radius", 250, [0]],
	["_message", "", [""]]
];

if (isNull _obj) exitWith {};

[_message] call ULP_fnc_hint;

private _trigger = createTrigger ["EmptyDetector", getPos _obj, false];
_trigger setVariable ["popup_cartel", _obj];

_trigger setTriggerArea [_radius, _radius, 0, false];
_trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];
_trigger setTriggerStatements ["this && { (vehicle player) in thisList }", "[""PopupCartel"", ""create"", true, thisTrigger getVariable ""popup_cartel""] call ULP_fnc_cartelHud", "(thisTrigger getVariable ""popup_cartel"") setVariable [""pauseTime"", nil]; [""PopupCartel"", ""remove""] call ULP_fnc_cartelHud"];

_obj setVariable ["trigger", _trigger];

[{ isNull (_this select 0) }, [_obj, _trigger], { deleteVehicle (_this select 1); }] call ULP_fnc_waitUntilExecute;