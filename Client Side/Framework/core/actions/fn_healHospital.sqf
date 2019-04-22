#include "..\..\script_macros.hpp"
/*
    File: fn_healHospital.sqf
    Author: Bryan "Tonic" Boardwine
    Reworked: Jesse "TKCJesse" Schultz

    Description:
    Prompts user with a confirmation dialog to heal themselves.
    Used at the hospitals to restore health to full.
    Note: Dialog helps stop a few issues regarding money loss.
*/
private ["_healCost","_action"];
if (life_action_inUse) exitWith {};
if ((damage player) < 0.01) exitWith {hint "You do not need to receive first aid!"};
_healCost = LIFE_SETTINGS(getNumber,"hospital_heal_fee");
if (CASH < _healCost) exitWith {hint format ["You do not have £%1 to receive first aid.",[_healCost] call life_fnc_numberText];};

life_action_inUse = true;
_action = [
    format ["Spend £%1 to recieve first aid.",[_healCost] call life_fnc_numberText],
    localize "Doctor",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    titleText[localize "Please stay still...","PLAIN"];
    closeDialog 0;
    uiSleep 8;
    if (player distance (_this select 0) > 5) exitWith {life_action_inUse = false; titleText["You need to be within 5m while the doctor is providing first aid.","PLAIN"]};
    titleText["You are now fully healed.","PLAIN"];
    player setDamage 0;
    CASH = CASH - _healCost;
    life_action_inUse = false;
} else {
    hint "Action Cancelled.";
    closeDialog 0;
    life_action_inUse = false;
};
