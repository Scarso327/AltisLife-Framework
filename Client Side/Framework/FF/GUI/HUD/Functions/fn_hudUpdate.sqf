#include "..\..\..\..\script_macros.hpp"
#include "..\macros.hpp"

/*
    File: fn_hudUpdate.sqf
    Author: Daniel Stuart

    Description:
    Updates the HUD when it needs to.
*/
disableSerialization;

if (isNull LIFEdisplay) then {[] call FF_fnc_hudSetup;};
LIFEctrl(IDC_LIFE_BAR_FOOD) progressSetPosition (1 / (100 / life_hunger));
LIFEctrl(IDC_LIFE_BAR_WATER) progressSetPosition (1 / (100 / life_thirst));
LIFEctrl(IDC_LIFE_BAR_HEALTH) progressSetPosition (1 - (damage player));

LIFEctrl(IDC_LIFE_FOOD_TEXT) ctrlsetText format["%1", [life_hunger, "%"] joinString ""];
LIFEctrl(IDC_LIFE_WATER_TEXT) ctrlsetText format["%1", [life_thirst, "%"] joinString ""];
LIFEctrl(IDC_LIFE_HEALTH_TEXT) ctrlsetText format["%1", [round((1 - (damage player)) * 100), "%"] joinString ""];

// Update Cash!
LIFEctrl(IDC_LIFE_CASH_TEXT) ctrlSetStructuredText parseText format["<t align='right'>£%1</t>", [CASH] call life_fnc_numberText];