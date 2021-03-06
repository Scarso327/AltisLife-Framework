/*
** Author: Jack "Scarso" Farhall
** Description: 
*/

_this params [
    ["_entity", objNull, [objNull]],
    ["_corpse", objNull, [objNull]]
];

if (isNull _corpse) exitWith {};

deleteVehicle _corpse;