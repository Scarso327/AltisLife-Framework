#include "..\..\..\..\script_macros.hpp"
/*
    File: fn_hudSetup.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Setups the hud for the player?
*/
disableSerialization;

cutRsc ["RscPlayerHUD", "PLAIN", 2, false];
[] call FF_fnc_hudUpdate;

[] spawn
{
    private ["_dam"];
    for "_i" from 0 to 1 step 0 do {
        _dam = damage player;
        _money = CASH;
        waitUntil {!((damage player) isEqualTo _dam) || !(CASH isEqualTo _money)};
        [] call FF_fnc_hudUpdate;
    };
};
