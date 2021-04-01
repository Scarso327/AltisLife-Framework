/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initPlayer";

_this params [
	["_setTags", true, [false]]
];

if (_setTags) then {
	[] call ULP_fnc_setTags;
};

player enableFatigue false;
player enableStamina false;

player setUnitTrait ["loadCoef", getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "loadCoef")];
player enableAimPrecision ([getNumber (missionConfigFile >> "CfgSettings" >> "Player" >> "aimPrecision")] call ULP_fnc_bool);