/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initMissions";

["Initialising Missions"] call ULP_fnc_logIt;

// On Incap & Died to stop force respawns to spawn closer...
["Incapacitated", { [] call ULP_fnc_failMissions; }] call ULP_fnc_addEventHandler;
["Died", { [] call ULP_fnc_failMissions; }] call ULP_fnc_addEventHandler;