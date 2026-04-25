/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\ulp_server\script_macros.hpp"
scopeName "fn_getDayName";

private _query = ["SELECT DAYNAME(CURDATE())", 2] call ULP_DB_fnc_asyncCall;
_query params [["_day", "", [""]]];

_day