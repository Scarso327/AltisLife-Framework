/*
** Author: Jack "Scarso" Farhall
** Description: Returns if we've reached our garage limit for this vehicle type
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_isAtGarageLimit";

_this params [
	["_className", "", [""]],
	["_steamId", "", [""]],
	["_faction", "", [""]],
	["_garageLimit", -1, [0]]
];

if (_garageLimit isEqualTo -1) exitWith { false };

if (_className isEqualTo "" || { _steamId isEqualTo "" } || { _faction isEqualTo "" }) exitWith { true };

private _query = [format["SELECT count(`id`) FROM `vehicles` WHERE `pid`='%1' AND `classname`='%2' AND `faction`='%3' AND `sold`='0'", _steamId, _className, _faction], 2] call DB_fnc_asyncCall;

_query params [
	["_vehicleCount", 0, [0]]
];

(_vehicleCount >= _garageLimit)