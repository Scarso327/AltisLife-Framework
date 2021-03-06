/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"

_this params [
    ["_unit",objNull,[objNull]],
    "",
    ["_uid","",[""]]
];

if (isNull _unit) exitWith {};

private _containers = nearestObjects[_unit, ["WeaponHolderSimulated"], 5];
{ deleteVehicle _x } forEach _containers;
deleteVehicle _unit;