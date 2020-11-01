/*
** Author: Jack "Scarso" Farhall
** Description: Asks the server to provide us with our information...
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_getPlayerInfo";

if (ULP_Loaded) exitWith {};

["Getting Player Information"] call ULP_fnc_logIt;

[player] remoteExec ["ULP_SRV_fnc_queryPlayerInfo", RSERV];