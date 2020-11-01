#include "..\..\script_macros.hpp"
/*
    File: fn_adminCompensate.sqf
    Author: ColinM9991

    Description:
    Figure it out.
*/
private ["_value","_action"];
if (FETCH_CONST(life_adminlevel) < 2) exitWith {closeDialog 0; hint "Your Staff Level is not high enough.";};
_value = parseNumber(ctrlText 9922);
if (_value < 0) exitWith {};
if (_value > 999999) exitWith {hint "You can not go above £999,999."};

_action = [
    format ["You are about to give yourself £%1 to compensate to another player &lt;br/&gt;&lt;br/&gt;You must give this cash to the person you are compensating manually.",[_value] call life_fnc_numberText],
    localize "STR_Admin_Compensate",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    CASH = CASH + _value;
    hint format ["You have added £%1 to your account.",[_value] call life_fnc_numberText];
    closeDialog 0;
} else {
    hint "Action Cancelled";
    closeDialog 0;
};
