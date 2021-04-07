/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getDayName";

private _query = ["SELECT DAYNAME(CURDATE())", 2] call DB_fnc_asyncCall;
_query params [["_day", "", [""]]];

_day