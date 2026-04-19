/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\ulp_server\script_macros.hpp"
scopeName "fn_getLocalTime";

private _extdbTime = [(EXTDB "9:LOCAL_TIME")] call ULP_DB_fnc_mresToArray;

_extdbTime params [
	"", ["_localTime", [], [[]]]
];

_localTime