#include "..\..\script_macros.hpp"

private ["_healCost","_action"];
if (life_action_inUse) exitWith {};
if ((damage player) < 0.01) exitWith {hint "You are in perfect health."};

life_action_inUse = true;
_action = [
    "Do you wish to recieve medical assistance?",
    "Okay, please stay still...",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    titleText["Please stay still!","PLAIN"];
    closeDialog 0;
    uiSleep 8;
    if (player distance (_this select 0) > 5) exitWith {life_action_inUse = false; titleText["You must stay nearby to recieve medical assistance!","PLAIN"]};
    titleText["You are now in perfect health..","PLAIN"];
    player setDamage 0;
    life_action_inUse = false;
} else {
    hint "Treatment Cancelled";
    closeDialog 0;
    life_action_inUse = false;
};
