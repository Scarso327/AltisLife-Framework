/*
** Author: Jack "Scarso" Farhall
** Description: Asks the server to provide us with our information...
*/
#include "..\..\script_macros.hpp"
scopeName "fn_logIt";

_this params [
	["_msg", "N/A", [""]],
	["_isDebug", false, [true]]
];

if (_isDebug && { !IS_DEBUG_MODE }) exitWith {};

private _message = format["[ULP][v%1]%2 %3", LIFE_SETTINGS(getText,"framework_version"), ["", "[DEBUG]"] select (IS_DEBUG_MODE), _msg];

diag_log _message;

if (hasInterface && { IS_DEBUG_MODE }) then {
	systemChat _message;
};