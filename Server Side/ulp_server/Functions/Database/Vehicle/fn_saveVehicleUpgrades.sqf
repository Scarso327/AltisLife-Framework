/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\ulp_server\script_macros.hpp"
scopeName "fn_saveVehicleUpgrades";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith {};

private _id = _vehicle getVariable ["vehicle_id", -1];
if (_id < 0) exitWith {};

private _upgrades = _vehicle getVariable ["object_upgrades", createHashMap];

[format[
	"UPDATE `vehicles` SET `upgrades`='%2' WHERE `id`='%1'", 
	[_id, ""] call ULP_fnc_numberText, [_upgrades] call ULP_DB_fnc_mresArray
], 1] call ULP_DB_fnc_asyncCall;