/*
    @File: fn_hudUpdate.sqf

    @Author: Daniel Stuart
    @Editor: Jack "Scarso" Farhall (Toggle Display, XP System, Cash Text)

    @Description: Updates the HUD when it needs to.
*/
#include "..\..\..\..\script_macros.hpp"
#include "..\macros.hpp"

disableSerialization;

if (isNull LIFEdisplay) then {[] call FF_fnc_hudSetup;};

private _allElements = [
    // Backgrounds
    LIFEctrl(IDC_LIFE_BAR_FOOD_BACK),
    LIFEctrl(IDC_LIFE_BAR_WATER_BACK),
    LIFEctrl(IDC_LIFE_BAR_HEALTH_BACK),
    LIFEctrl(IDC_LIFE_BAR_XP_BACK),
    LIFEctrl(IDC_LIFE_NUM_NXTLVL_BACK),
    LIFEctrl(IDC_LIFE_NUM_CURLVL_BACK),
    // Progress Bars
    LIFEctrl(IDC_LIFE_BAR_FOOD),
    LIFEctrl(IDC_LIFE_BAR_WATER),
    LIFEctrl(IDC_LIFE_BAR_HEALTH),
    LIFEctrl(IDC_LIFE_BAR_XP),
    // Text
    LIFEctrl(IDC_LIFE_FOOD_TEXT),
    LIFEctrl(IDC_LIFE_WATER_TEXT),
    LIFEctrl(IDC_LIFE_HEALTH_TEXT),
    LIFEctrl(IDC_LIFE_CASH_TEXT),
    LIFEctrl(IDC_LIFE_XP_TEXT),
    LIFEctrl(IDC_LIFE_CURLVL_TEXT),
    LIFEctrl(IDC_LIFE_NXTLVL_TEXT)
];

{ _x ctrlShow (!(FF_hideHUD)) } forEach _allElements; // Toggle HUD Visibility...

// Update UI Elements...
LIFEctrl(IDC_LIFE_BAR_FOOD) progressSetPosition (1 / (100 / life_hunger));
LIFEctrl(IDC_LIFE_BAR_WATER) progressSetPosition (1 / (100 / life_thirst));
LIFEctrl(IDC_LIFE_BAR_HEALTH) progressSetPosition (1 - (damage player));

LIFEctrl(IDC_LIFE_FOOD_TEXT) ctrlSetStructuredText parseText format["Food<t align='right'>%1</t>", [life_hunger, "%"] joinString ""];
LIFEctrl(IDC_LIFE_WATER_TEXT) ctrlSetStructuredText parseText format["Water<t align='right'>%1</t>", [life_thirst, "%"] joinString ""];
LIFEctrl(IDC_LIFE_HEALTH_TEXT) ctrlSetStructuredText parseText format["Health<t align='right'>%1</t>", [round((1 - (damage player)) * 100), "%"] joinString ""];

// Update Cash!
LIFEctrl(IDC_LIFE_CASH_TEXT) ctrlSetStructuredText parseText format["<t align='right'>£%1</t>", [CASH] call life_fnc_numberText];