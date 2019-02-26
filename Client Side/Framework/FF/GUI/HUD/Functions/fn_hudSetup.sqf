#include "..\..\..\..\script_macros.hpp"
#include "..\macros.hpp"
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

// SETUP XP UI (Initial)...
#define MAXLVL (getNumber(missionConfigFile >> "CfgLevels" >> "maxLevel"))

private _level = switch true do {
    case (FF_Level isEqualTo MAXLVL): { MAXLVL };
    default { (FF_Level + 1) };
};

private _neededXP = getNumber(missionConfigFile >> "CfgLevels" >> format["level_%1", _level] >> "expRequired");

// Progression
LIFEctrl(IDC_LIFE_BAR_XP) progressSetPosition (FF_XP / _neededXP);

// Text
LIFEctrl(IDC_LIFE_CURLVL_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1</t>", FF_Level];
LIFEctrl(IDC_LIFE_NXTLVL_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1</t>", _level];
LIFEctrl(IDC_LIFE_XP_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1 / %2</t>", FF_XP, [_neededXP] call life_fnc_numberText];