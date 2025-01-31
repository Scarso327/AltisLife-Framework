/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initVars";

/* Session Variables */
ULP_Date = [2021, 1, 1];
ULP_FirstSpawn = true;
ULP_Imprisioned = false;
ULP_Prison_Time = 0;
ULP_New = true;
ULP_Loaded = false;
ULP_Last_Sync = time;

/* Setting Variables */
ULP_Settings_EnableSide = false;
ULP_FadeSound = false;

/* Player Variables */
ULP_Paycheck = {0};
ULP_Gear = [];
ULP_Holsted = "";
ULP_Licenses = [];
ULP_Houses = [];
ULP_Keys = [];
ULP_Inventory = createHashMap;
ULP_Perks = createHashMap;
ULP_CarryWeight = 0;
ULP_Missions = createHashMap;

ULP_Prestige = 0;
ULP_Level = 1;
ULP_XP = 0;

ULP_Gang_ID = -1;

/* Player State Variables */
ULP_Ability_Cooldown = time;
ULP_Effects = [];

/* Default Altis Life Variables */
life_action_inUse = false;