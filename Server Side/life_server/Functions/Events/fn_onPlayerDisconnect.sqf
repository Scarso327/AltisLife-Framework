/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onPlayerDisconnect";

_this params [
    ["_unit", objNull, [objNull]]
];

if (isNull _unit) exitWith {};

[_unit] call ULP_SRV_fnc_unregisterSession;

private _containers = nearestObjects[_unit, ["WeaponHolderSimulated"], 5];
{ deleteVehicle _x } forEach _containers;
deleteVehicle _unit;