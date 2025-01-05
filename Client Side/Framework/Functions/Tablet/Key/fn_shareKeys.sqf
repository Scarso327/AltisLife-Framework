/*
** Author: Jack "Scarso" Farhall
** Description: Shares keys with everyone in vehicle as long as you're in it
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_shareKeys";

_this params [ "_button" ];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _carView = _display displayCtrl 23092;

private _vehicle = _display getVariable ["vehicle", objNull];

if (isNull _vehicle) exitWith { _carView ctrlShow false; };
if !(ctrlShown _carView) then { _carView ctrlShow true; };

if !((vehicle player) isEqualTo _vehicle) exitWith { ["You must be in this vehicle to share it's keys with it's occupants"] call ULP_fnc_hint; };

private _crew = (crew _vehicle) - [player];

if ((count _crew) isEqualTo 0) exitWith { ["There isn't anyone to give keys to"] call ULP_fnc_hint; };

["KeysGiven", [_vehicle, player]] remoteExecCall ["ULP_fnc_invokeEvent", _crew];
["You have given keys to everyone in this vehicle."] call ULP_fnc_hint;