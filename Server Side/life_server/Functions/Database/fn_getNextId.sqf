/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getNextId";

_this params [
	["_table", "", [""]]
];

private _query = [format["SHOW TABLE STATUS LIKE '%1'", _table], 2] call DB_fnc_asyncCall;
(_query param [10, 1, [0]])