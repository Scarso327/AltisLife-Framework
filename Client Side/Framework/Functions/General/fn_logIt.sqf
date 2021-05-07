/*
** Author: Jack "Scarso" Farhall
** Description: Asks the server to provide us with our information...
*/
#include "..\..\script_macros.hpp"
scopeName "fn_logIt";

_this params [
	["_msg", "N/A", [""]]
];

diag_log format["[ULP][v%1] %2", LIFE_SETTINGS(getText,"framework_version"), _msg];