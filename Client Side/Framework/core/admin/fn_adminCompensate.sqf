#include "..\..\script_macros.hpp"
/*
    File: fn_adminCompensate.sqf
    Author: ColinM9991

    Description:
    Figure it out.
*/
private ["_value","_action"];
if (FETCH_CONST(life_adminlevel) < 2) exitWith {closeDialog 0; hint "Your staff position is not high enough.";};
_value = parseNumber(ctrlText 9922);
if (_value < 0) exitWith {};
if (_value > 999999) exitWith {hint "A number above £999,999 is not valid."};

_action = [
    format ["You are about to compensate yourself £%1.",[_value] call life_fnc_numberText],
    "Compensate",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    CASH = CASH + _value;
    hint format ["You have compensated yourself £%1.",[_value] call life_fnc_numberText];
    closeDialog 0;
} else {
    hint "Action Cancelled.";
    closeDialog 0;
};
