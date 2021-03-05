/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_storeVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_storeVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_location", objNull, [objNull]],
	["_types", ["Car", "Air", "Ship"], [[]]]
];

if (isNull _location) exitWith {};

private _near = _location nearEntities [_types, 15];
private _vehicle = _near param [(_near findIf {
	alive _x && { ((keys (cursorObject getVariable ["vehicle_owners", [[]]])) param [0, ""]) isEqualTo (getPlayerUID player) }
}), objNull];

if (isNil "_vehicle" || { isNull _vehicle } || { !(alive _vehicle) }) exitWith {
	hint "No vehicles near stand to store...";
};

if ([[player] call ULP_fnc_getFaction, "vehicles"] call ULP_fnc_factionPresistant && { (_vehicle getVariable ["vehicle_id", -1]) >= 0  }) exitWith {
	["VehicleStored", { hint "Vehicle has been stored."; }, true] call ULP_fnc_addEventHandler;
	[_vehicle] remoteExecCall ["ULP_SRV_fnc_storeVehicle", RSERV];
};

deleteVehicle _vehicle;
hint "Vehicle has been stored.";