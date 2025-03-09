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
	["_texture", "", [""]],
	["_spawn", [[0, 0, 0], 0], [[]]],
	["_garageLimit", -1, [0]],
	["_shareKeys", false, [true]]
];

if (_steamid isEqualTo "" || { _name isEqualTo "" } || { !(isClass (missionConfigFile >> "CfgFactions" >> _faction))}) exitWith {};

if ([_class, _steamid, _faction, _garageLimit] call ULP_SRV_fnc_isAtGarageLimit) exitWith {
	["VehicleBought", [[_class], _shareKeys, true, _price]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

(_class call BIS_fnc_objectType) params ["", "_type"];

// Get ID...
private _id = ["vehicles"] call ULP_SRV_fnc_getNextId;

// Insert...
[format[
	"INSERT INTO `vehicles` (`id`, `pid`, `faction`, `classname`, `type`, `texture`, `active`, `upgrades`) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '""[]""');", 
	[_id, ""] call ULP_fnc_numberText, _steamid, _faction, _class, _type, _texture, [1, 0] select (_spawn isEqualTo [])
], 1] call DB_fnc_asyncCall;

["VehicleBought", [[_class, _spawn, _texture, _id], _shareKeys]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];