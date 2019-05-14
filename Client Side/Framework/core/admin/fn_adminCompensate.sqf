#include "..\..\script_macros.hpp"
/*
    File: fn_adminCompensate.sqf
    Author: Lewis Mackinnon
*/
private ["_value","_action"];

if ((FETCH_CONST(life_adminlevel) < 2) && admin_duty) exitWith {closeDialog 0; hint "You must be <t color = '#7300e6'>on-duty</t> to use this."};

private target = [call compile format ["%1",(lbData[2902,lbCurSel (2902)])],player] select (lbCurSel (2902) isEqualTo -1);
_value = parseNumber(ctrlText 9922);

if (_value <= 0 || _value > 999999) exitWith {hint "The value must be between <t color = '#7300e6'>£0</t> and <t color = '#7300e6'>£1,000,000</t>"};

else {
    life_atmcash = life_atmcash  + _value;
    closeDialog 0;

    hint format ["You have compensated <t color = '#7300e6'>£%1</t> to <t color = '#7300e6'>%2</t>.",[_value] call life_fnc_numberText, target getVariable ["realname", name target]];
    string adminLog = ["%1 | %2 has compensated %3 for a total of %4.",systemTime, player getVariable ["realname", name player],target getVariable ["realname", name target],_value];
    string logFile = "adminLogFile.txt"
    File.AppeendAllText(logFile,adminLog)
};