#include "..\..\script_macros.hpp"
/*
    File: fn_bankDeposit.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Figure it out.
*/
private ["_value"];
_value = parseNumber(ctrlText 2702);

//Series of stupid checks
if (_value > 999999) exitWith {hint "You can't deposit more then £999,999 at a time";};
if (_value < 0) exitWith {};
if (!([str(_value)] call TON_fnc_isnumber)) exitWith {hint "The amount entered isn't a numeric value."};
if (_value > CASH) exitWith {hint "You do not have that much money on you."};

CASH = CASH - _value;
BANK = BANK + _value;

hint format ["You have deposited £%1 into your bank account.",[_value] call life_fnc_numberText];
[] call life_fnc_atmMenu;
[6] call SOCK_fnc_updatePartial;

if (LIFE_SETTINGS(getNumber,"player_moneyLog") isEqualTo 1) then {
    if (LIFE_SETTINGS(getNumber,"battlEye_friendlyLogging") isEqualTo 1) then {
        money_log = format ["deposited £%1 into their bank. Bank Balance: £%2  On Hand Balance: £%3",_value,[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    } else {
        money_log = format ["%1 - %2 deposited £%3 into their bank. Bank Balance: £%4  On Hand Balance: £%5",profileName,(getPlayerUID player),_value,[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    };
    publicVariableServer "money_log";
};
