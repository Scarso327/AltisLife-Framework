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

private _level = format["level_%1", (parseNumber(FF_Level) + 1)];
private _neededXP = M_CONFIG(getNumber,"CfgLevels",_level,"expRequired");

LIFEctrl(IDC_LIFE_BAR_XP) progressSetPosition (parseNumber(FF_XP) / _neededXP);

// XP Text
LIFEctrl(IDC_LIFE_XP_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1 / %2</t>", 
    FF_XP,
    [_neededXP] call life_fnc_numberText
];

// Cur Lvl &&  Nxt Lvl
LIFEctrl(IDC_LIFE_CURLVL_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1</t>", FF_Level];
LIFEctrl(IDC_LIFE_NXTLVL_TEXT) ctrlSetStructuredText parseText format["<t align='center'>%1</t>", (parseNumber(FF_Level) + 1)];