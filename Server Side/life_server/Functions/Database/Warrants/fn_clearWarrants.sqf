/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_clearWarrants";

_this params [
	["_pid", "", [""]]
];

if (_pid isEqualTo "") exitWith { false };

[format["UPDATE warrants SET active='0' WHERE pid='%1' AND active='1'", _pid], 1] call DB_fnc_asyncCall;
true