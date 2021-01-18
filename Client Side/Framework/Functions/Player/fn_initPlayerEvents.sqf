/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPlayerEvents";

player addEventHandler ["Killed", { _this call ULP_fnc_onKilled }];
player addEventHandler ["Respawn", { _this call ULP_fnc_onRespawn }];
player addEventHandler ["HandleDamage", { _this call ULP_fnc_onDamaged }];
player addEventHandler ["HandleRating", {0}];