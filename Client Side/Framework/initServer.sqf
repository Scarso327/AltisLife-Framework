/*
** Author: Jack "Scarso" Farhall
** Description: Checks if we have the server side package available and calls to start initialisation
*/
#include "script_macros.hpp"

if (isClass (configFile >> "CfgPatches" >> "ULPServer")) then {
	[] call ULP_SRV_fnc_init;
};