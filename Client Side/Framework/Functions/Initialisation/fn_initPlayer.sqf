/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPlayer";

["Initialising Player"] call ULP_fnc_logIt;

[] call ULP_fnc_setTags;

player enableFatigue false;
player enableStamina false;

player setUnitTrait ["loadCoef", getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "loadCoef")];
player enableAimPrecision ([getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "aimPrecision")] call ULP_fnc_bool);