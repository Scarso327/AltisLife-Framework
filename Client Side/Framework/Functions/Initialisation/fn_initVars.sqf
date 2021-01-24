/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initVars";

/* Session Variables */
ULP_Date = [2021, 1, 1];
ULP_New = true;
ULP_Loaded = false;
ULP_Last_Sync = time;

/* Setting Variables */
ULP_Settings_EnableSide = false;

/* Player Variables */
ULP_Paycheck = {0};
ULP_Gear = [];
ULP_Holsted = "";
ULP_Liceneses = [];
ULP_Houses = [];

ULP_Gang_ID = -1;

/* Player State Variables */
ULP_Survival_Thirst = 100;
ULP_Survival_Hunger = 100;

CASH = 0;
BANK = LIFE_SETTINGS(getNumber,"starting_bank");

/* Default Altis Life Variables */
life_action_inUse = false;