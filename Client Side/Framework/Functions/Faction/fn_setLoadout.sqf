/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setLoadout";

[missionConfigFile >> "CfgFactions" >> ([player] call ULP_fnc_getFaction) >> "Loadout"] call ULP_fnc_setCfgLoadout;