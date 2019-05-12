#include "..\..\script_macros.hpp"
/*
    File: fn_adminCompensate.sqf
    Author: Lewis Mackinnon
*/
private ["_value","_action"];

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty isEqualTo 0) exitWith {closeDialog 0; hint "You must be on-duty to use this."};

_value = parseNumber(ctrlText 9922);
if (_value <= 0 || _value > 999999) exitWith {hint "The value must be between £0 and £1,000,000"};

else {
    CASH = CASH + _value;
    hint format ["You have compensated yourself <t color = '#7300e6'>£%1</t>.",[_value] call life_fnc_numberText];
    closeDialog 0;
};
