/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setHouseShared";

_this params [
	["_id", -1, [0]],
	["_name", "", [""]]
];

if (_id < 0) exitWith {};

_id = [_id, ""] call ULP_fnc_numberText;

[format[
	"UPDATE houses SET name='%2' WHERE id='%1'", 
	_id, [_name] call DB_fnc_mresString
], 1] call DB_fnc_asyncCall;