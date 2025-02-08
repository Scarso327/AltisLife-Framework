/*
** Author: Jack "Scarso" Farhall
** Description: Asks the server to provide us with our information...
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_getPlayerInfo";

if (ULP_Loaded) exitWith {};

["Getting Player Information"] call ULP_fnc_logIt;

ULP_FailedEventId = ["PlayerInformationQueryFailed", {
	if !(isNil "ULP_ID") exitWith {}; // We already have our data set??

	["Failed to create spawn dialog or ULP_ID wasn't configured indicating failed data query"] call ULP_fnc_logIt;
	endMission "InitFailed";
}, true] call ULP_fnc_addEventHandler;

[player] remoteExecCall ["ULP_SRV_fnc_queryPlayerInfo", RSERV];