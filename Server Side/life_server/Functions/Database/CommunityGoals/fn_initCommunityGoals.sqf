/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initCommunityGoals";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_initCommunityGoals, _this] call ULP_fnc_directCall;
};

["Setting Up Community Goals..."] call ULP_fnc_logIt;

