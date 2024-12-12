/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_retrieveVehicle";

_this params [
	["_id", -1, [0]]
];

if (_id < 0) exitWith {};

_id = [_id, ""] call ULP_fnc_numberText;

[format[
	"UPDATE `vehicles` SET `active`='1', `impound`='0' WHERE `id`='%1'", 
	_id
], 1] call DB_fnc_asyncCall;