/*
    File: fn_civLoadout.sqf
    Author: Tobias 'Xetoxyc' Sittenauer

    Description:
    Loads the civs out with the default gear, with randomized clothing.
*/
#include "..\..\script_macros.hpp"

private _handle = [] spawn life_fnc_stripDownPlayer;
waitUntil {scriptDone _handle};

player addUniform "U_C_Poor_1";

player linkItem "ItemMap";
player linkItem "ItemCompass";
player linkItem "ItemWatch";

player addItem "FirstAidKit";

if (HAS_PERK("mindfulPlanner")) then { 
    player linkItem "ItemGPS";

    player addItem "NVGoggles";
    player assignItem "NVGoggles";
}; 

[] call FF(playerSkins);
[] call life_fnc_saveGear; 
