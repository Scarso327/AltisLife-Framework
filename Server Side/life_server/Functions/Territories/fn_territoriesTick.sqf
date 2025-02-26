/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_territoriesTick";

if (ULP_Territories isEqualTo []) exitWith {};

private _tickDelay = getNumber (missionConfigFile >> "CfgTerritories" >> "tickTime");

missionNamespace setVariable ["ULP_SRV_TerritoriesNextTime", serverTime + _tickDelay, true];

[ _tickDelay, [] , {

	diag_log "tick";

	[] call ULP_SRV_fnc_territoriesTick; // Restart tick...
}] call ULP_fnc_waitExecute;