/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getGatherZone";

_this params [
	["_unit", player, [objNull]]
];

private _cfg = ("isClass _x && { isArray (_x >> ""areas"") }" configClasses (missionConfigFile >> "CfgGathering"));

(_cfg param [(_cfg findIf {
	!((getArray (_x >> "areas") select { (_unit distance (getMarkerPos (_x select 0))) <= (_x select 1) }) isEqualTo [])
}), configNull])