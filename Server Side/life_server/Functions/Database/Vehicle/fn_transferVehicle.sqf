/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_transferVehicle";

_this params [
	["_owner", objNull, [objNull]],
	["_newOwner", objNull, [objNull]],
	["_vehicleId", -1, [0]]
];

if (isNull _owner || { isNull _newOwner } || { _vehicleId isEqualTo -1 }) exitWith {};

private _steamId = getPlayerUID _owner;
private _newSteamId = getPlayerUID _newOwner;

[format["UPDATE vehicles SET pid='%1' WHERE pid='%2' AND id='%3'", _steamId, _newSteamId, _vehicleId], 1] call DB_fnc_asyncCall;