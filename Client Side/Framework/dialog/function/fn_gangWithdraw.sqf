#include "..\..\script_macros.hpp"
/*
    File: fn_gangWithdraw.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Withdraws money from the gang bank.
*/
private ["_value"];
_value = parseNumber(ctrlText 2702);
_gFund = GANG_FUNDS;
group player setVariable ["gbank_in_use_by",player,true];

//Series of stupid checks
if (isNil {(group player) getVariable "gang_name"}) exitWith {hint "You are not in an organisation."}; // Checks if player isn't in a gang
if (_value > 999999) exitWith {hint "You can't withdraw more then £999,999";};
if (_value < 0) exitWith {};
if (!([str(_value)] call TON_fnc_isnumber)) exitWith {hint "The amount entered isn't a numeric value."};
if (_value > _gFund) exitWith {hint "You don't have that much in your oranigation's account."};
if (_val < 1 && _gFund > 20000000) exitWith {hint "You can't withdraw less then £1."}; //Temp fix for something.
if ((group player getVariable ["gbank_in_use_by",player]) != player) exitWith {hint "Someone is already trying to withdraw from your orgnisation's account."}; //Check if it's in use.

_gFund = _gFund - _value;
CASH = CASH + _value;
group player setVariable ["gang_bank",_gFund,true];

if (life_HC_isActive) then {
    [1,group player] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
} else {
    [1,group player] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
};

hint format ["You have withdrawn £%1 from your organisation's account.",[_value] call life_fnc_numberText];
[] call life_fnc_atmMenu;
[6] call SOCK_fnc_updatePartial;

if (LIFE_SETTINGS(getNumber,"player_moneyLog") isEqualTo 1) then {
    if (LIFE_SETTINGS(getNumber,"battlEye_friendlyLogging") isEqualTo 1) then {
        money_log = format ["withdrew £%1 from their gang bank. Gang Bank Balance: £%2  Bank Balance: £%3  On Hand Balance: £%4",_value,[_gFund] call life_fnc_numberText,[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    } else {
        money_log = format ["%1 - %2 withdrew £%3 from their gang bank. Gang Bank Balance: £%4  Bank Balance: £%5  On Hand Balance: £%6",profileName,(getPlayerUID player),_value,[_gFund] call life_fnc_numberText,[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    };
    publicVariableServer "money_log";
};
