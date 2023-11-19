/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_transferVehicle";

_this params [
	["_owner", objNull, [objNull, ""]],
	["_newOwner", objNull, [objNull]],
	["_vehicleId", -1, [0]],
	["_className", "", [""]],
	["_faction", "", [""]],
	["_ignoreGarageLimit", false, [true]]
];

private _steamId = ([
	getPlayerUID _owner,
	_owner
] select (_owner isEqualType ""));

if (isNull _newOwner || { _steamId isEqualTo "" } || { _className isEqualTo "" } || { _faction isEqualTo "" } || { _vehicleId isEqualTo -1 }) exitWith {};

private _newSteamId = getPlayerUID _newOwner;

private _hasVehicleCollectorPerk = "VehicleCollector" in ([_newOwner, "Perks"] call ULP_SRV_fnc_getSessionField);

if ([_className, _newSteamId, _faction, _hasVehicleCollectorPerk, _ignoreGarageLimit] call ULP_SRV_fnc_isAtGarageLimit) exitWith {
	["VehicleTransferred", ["Vehicle transfer was declined because the recipient is at their garage limit for this vehicle type"]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

// The SQL has some failsafes with active, sold, and impound checks. Success message will still be sent
// even if these are hit but we should've already stopped this client side just better to be safe than sorry
[format["UPDATE vehicles SET pid='%1' WHERE pid='%2' AND id='%3' AND active='0' AND sold='0' AND impound='0'", _newSteamId, _steamId, [_vehicleId, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
["VehicleTransferred", []] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];