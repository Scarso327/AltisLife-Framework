/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getLocalTime";

private _extdbTime = [(EXTDB "9:LOCAL_TIME")] call DB_fnc_mresToArray;

_extdbTime params [
	"", ["_localTime", [], [[]]]
];

_localTime