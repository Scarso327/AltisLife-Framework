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

private _id = [_steamid, _name, _faction, _class, _texture, _spawn] call ULP_SRV_fnc_insertVehicle;
if (_id isEqualTo -1) exitWith {};

["VehicleBought", [[_class, _spawn, _texture, _id], _shareKeys]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];