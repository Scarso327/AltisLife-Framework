/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setLoadout";

// Wipe Inventory...
ULP_Inventory = createHashMap;
ULP_CarryWeight = 0;

[missionConfigFile >> "CfgFactions" >> ([player] call ULP_fnc_getFaction) >> "Loadout"] call ULP_fnc_setCfgLoadout;