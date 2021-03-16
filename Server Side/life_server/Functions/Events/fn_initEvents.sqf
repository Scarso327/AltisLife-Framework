/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initEvents";

addMissionEventHandler ["EntityRespawned", { _this call ULP_SRV_fnc_onPlayerRespawn; }];
addMissionEventHandler ["HandleDisconnect", { _this call ULP_SRV_fnc_onPlayerDisconnect; false }];