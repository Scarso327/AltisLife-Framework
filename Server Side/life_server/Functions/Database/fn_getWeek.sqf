/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getWeek";

private _query = ["SELECT WEEK(CURDATE())", 2] call DB_fnc_asyncCall;
_query params [["_week", -1, [0]]];

(_query select 0)