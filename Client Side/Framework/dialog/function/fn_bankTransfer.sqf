#include "..\..\script_macros.hpp"
/*
    File: fn_bankTransfer.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Figure it out again.
*/
private ["_value","_unit","_tax"];
_value = parseNumber(ctrlText 2702);
_unit = call compile format ["%1",(lbData[2703,(lbCurSel 2703)])];
if (isNull _unit) exitWith {};
if ((lbCurSel 2703) isEqualTo -1) exitWith {hint "You need to select someone to transfer to."};
if (isNil "_unit") exitWith {hint "The person selected doesn't seem to exist."};
if (_value > 999999) exitWith {hint "You can't transfer more then £999,999.";};
if (_value < 0) exitWith {};
if (!([str(_value)] call TON_fnc_isnumber)) exitWith {hint "The amount entered isn't a numeric value."};
if (_value > BANK) exitWith {hint "You don't have that much in your bank account."};
_tax = _value * LIFE_SETTINGS(getNumber,"bank_transferTax");
if ((_value + _tax) > BANK) exitWith {hint format ["You don't have enough money in your bank account. To transfer £%1 you will need £%2 as a tax fee.",_value,_tax]};

BANK = BANK - (_value + _tax);

[_value,profileName] remoteExecCall ["life_fnc_wireTransfer",_unit];
[] call life_fnc_atmMenu;
[1] call SOCK_fnc_updatePartial;
hint format ["You have transfered £%1 to %2.\n\nA A tax fee of £%3 was taken for the wire transfer.",[_value] call life_fnc_numberText,_unit getVariable ["realname",name _unit],[_tax] call life_fnc_numberText];


if (LIFE_SETTINGS(getNumber,"player_moneyLog") isEqualTo 1) then {
    if (LIFE_SETTINGS(getNumber,"battlEye_friendlyLogging") isEqualTo 1) then {
        money_log = format ["transferred £%1 to %2. Bank Balance: £%3  On Hand Balance: £%4",_value,_unit getVariable ["realname",name _unit],[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    } else {
        money_log = format ["%1 - %2 transferred £%3 to %4. Bank Balance: £%5  On Hand Balance: £%6",profileName,(getPlayerUID player),_value,_unit getVariable ["realname",name _unit],[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    };
    publicVariableServer "money_log";
};
