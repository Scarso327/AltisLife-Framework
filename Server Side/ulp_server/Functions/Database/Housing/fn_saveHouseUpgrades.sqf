/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\ulp_server\script_macros.hpp"
scopeName "fn_saveHouseUpgrades";

_this params [
	["_house", objNull, [objNull]]
];

if (isNull _house) exitWith {};

private _id = _house getVariable ["building_id", -1];
if (_id < 0) exitWith {};

private _upgrades = _house getVariable ["object_upgrades", createHashMap];

[format[
	"UPDATE `houses` SET `upgrades`='%2' WHERE `id`='%1'", 
	[_id, ""] call ULP_fnc_numberText, [_upgrades] call ULP_DB_fnc_mresArray
], 1] call ULP_DB_fnc_asyncCall;