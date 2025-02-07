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
	["_hasVehicleCollectorPerk", false, [true]],
	["_ignoreGarageLimit", false, [true]]
];

if (_ignoreGarageLimit) exitWith { false };

if (_className isEqualTo "" || { _steamId isEqualTo "" } || { _faction isEqualTo "" }) exitWith { true };

private _query = [format["SELECT count(`id`) FROM `vehicles` WHERE `pid`='%1' AND `classname`='%2' AND `faction`='%3' AND `sold`='0'", _steamId, _className, _faction], 2] call DB_fnc_asyncCall;

_query params [
	["_vehicleCount", 0, [0]]
];

private _garageLimit = getNumber (missionConfigFile >> "CfgVehicles" >> _class >> "garageLimit");
if (_hasVehicleCollectorPerk) then { _garageLimit = _garageLimit * 2 };

(_vehicleCount >= _garageLimit)