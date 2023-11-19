/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_createVehicle";

_this params [
	["_price", 0, [0]],
	["_steamid", "", [""]],
	["_name", "", [""]],
	["_faction", "", [""]],
	["_class", "", [""]],
	["_spawn", [[0, 0, 0], 0], [[]]],
	["_texture", "", [""]],
	["_hasVehicleCollectorPerk", false, [true]],
	["_ignoreGarageLimit", false, [true]],
	["_active", 1, [0]]
];

if (_steamid isEqualTo "" || { _name isEqualTo "" } || { !(isClass (missionConfigFile >> "CfgFactions" >> _faction))}) exitWith {};

if ([_class, _steamid, _faction, _hasVehicleCollectorPerk, _ignoreGarageLimit] call ULP_SRV_fnc_isAtGarageLimit) exitWith {
	["VehicleBought", [[_class], true, _price, _garageLimit]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

(_class call BIS_fnc_objectType) params ["", "_type"];

// Get ID...
private _id = ["vehicles"] call ULP_SRV_fnc_getNextId;

// Insert...
[format[
	"INSERT INTO vehicles (pid, faction, classname, type, texture, active) VALUES ('%1', '%2', '%3', '%4', '%5', '%6');", 
	_steamid, _faction, _class, _type, _texture, _active
], 1] call DB_fnc_asyncCall;

["VehicleBought", [[_class, _spawn, _texture, _id]]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];