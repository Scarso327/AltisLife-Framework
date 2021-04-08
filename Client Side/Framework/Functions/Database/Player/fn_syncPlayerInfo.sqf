/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_syncPlayerInfo";

if ([player] call ULP_fnc_onDuty) exitWith {};

private _packet = [profileName, getPlayerUID player, [player] call ULP_fnc_getFaction, CASH, BANK];

[] call ULP_fnc_saveGear;
_packet pushBack ULP_Gear;
_packet pushBack ULP_Licenses;

_packet pushBack [
	ULP_Survival_Hunger,
	ULP_Survival_Thirst,
	(damage player)
];

_packet remoteExecCall ["ULP_SRV_fnc_savePlayerInfo", RSERV];