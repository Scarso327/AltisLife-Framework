/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\ulp_server\script_macros.hpp"
scopeName "fn_hidePlayer";

_this params [
	["_unit", objNull, [objNull]],
	["_hide", true, [false]]
];

if (isNull _unit || { !(_unit getVariable ["srv_is_admin", false]) }) exitWith {};

_unit hideObjectGlobal _hide;