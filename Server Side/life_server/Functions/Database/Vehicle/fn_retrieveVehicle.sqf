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

_id = [_id] call DB_fnc_numberSafe;

[format[
	"UPDATE vehicles SET active='1' WHERE id='%1'", 
	_id
], 1] call DB_fnc_asyncCall;