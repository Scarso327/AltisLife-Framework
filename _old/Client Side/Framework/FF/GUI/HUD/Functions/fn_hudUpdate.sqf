/*
    @File: fn_hudUpdate.sqf

    @Author: Daniel Stuart
    @Editor: Jack "Scarso" Farhall (Toggle Display, XP System, Cash Text + Icons System)

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

private _icons = [];
private _iconBackground = LIFEctrl(IDC_LIFE_ICON_BACKGROUND);

// Delete all previous icons...
{
	if (_x isEqualType []) then {
		for "_i" from 0 to (count (_x) - 1) do { ctrlDelete (_x select _i) };
	} else {
		ctrlDelete _x;
	};
} forEach FF_UI_Elements;
FF_UI_Elements = []; // Wipe it...

// Get our active icons...
if !([player, "comms"] call FF(hasItem)) then { _icons pushBack "nocomms.paa" }; // Check if we have communications...
if ( !(isNull objectParent player) && ((vehicle player) isKindOf "Car")) then {
    if (FF_seatbelt) then { _icons pushBack "seatbelt.paa" }; // Seatbelt Icon...

    // Car Unlocked / Locked Icon...
    _icons pushBack ([
        "carUnlocked.paa",
        "carLocked.paa"
    ] select ((locked (vehicle player)) isEqualTo 2));
};

if (count(_icons) < 1) exitWith { _iconBackground ctrlShow false }; // No Icons to display...
_iconBackground ctrlShow true;

// Define the increase variables for the icons...
#define X_INC 0.021625
#define W_INC 0.020625

private _IDC = IDC_LIFE_ICON_CREATION;
private _xVal = 0.0153125;
private _wVal = 0.020625;

// Rest width...
_iconBackground ctrlSetPosition [0.015312 * safezoneW + safezoneX, 0.951 * safezoneH + safezoneY, _wVal * safezoneW, 0.022 * safezoneH];
_iconBackground ctrlCommit 0;

// Create new icons...
{
    private _icon = LIFEdisplay ctrlCreate ["Life_RscPictureKeepAspect", _IDC];
    _icon ctrlSetPosition [_xVal * safezoneW + safezoneX, 0.951 * safezoneH + safezoneY, 0.020625 * safezoneW, 0.022 * safezoneH];
    _icon ctrlsetText format["%1", ICON(_x)];

    FF_UI_Elements pushBack _icon; // So we can delete it later if required...
    _IDC = _IDC + 1; // Increase IDC...
    _xVal = _xVal + X_INC; // Increase X Value...

    // If it's not the first icon increase background width...
    if (_forEachIndex > 0) then {
        _wVal = _wVal + W_INC; // Increase the W value...

        _iconBackground ctrlSetPosition [0.015312 * safezoneW + safezoneX, 0.951 * safezoneH + safezoneY, _wVal * safezoneW, 0.022 * safezoneH];
        _iconBackground ctrlCommit 0; // Commit the background changes...
    };

    _icon ctrlCommit 0; // Commit the icon changes...
} forEach _icons;