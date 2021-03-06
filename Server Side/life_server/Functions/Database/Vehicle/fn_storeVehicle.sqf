/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_storeVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith {};

private _id = _vehicle getVariable ["vehicle_id", -1];
if (_id < 0) exitWith {};

_id = [_id, ""] call ULP_fnc_numberText;

[format[
	"UPDATE vehicles SET active='0' WHERE id='%1'", 
	_id
], 1] call DB_fnc_asyncCall;

deleteVehicle _vehicle;

["VehicleStored"] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];