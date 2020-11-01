#include "..\..\script_macros.hpp"
/*
    File: fn_robReceive.sqf
    Author: Bryan "Tonic" Boardwine

    Description:

*/
params [
    ["_cash",0,[0]],
    ["_victim",objNull,[objNull]],
    ["_robber",objNull,[objNull]]
];

if (_robber == _victim) exitWith {};
if (_cash isEqualTo 0) exitWith {titleText["They didn't have any cash...","PLAIN"]};

CASH = CASH + _cash;
[0] call SOCK_fnc_updatePartial;
titleText[format ["You stole £%1",[_cash] call life_fnc_numberText],"PLAIN"];

if (LIFE_SETTINGS(getNumber,"player_moneyLog") isEqualTo 1) then {
    if (LIFE_SETTINGS(getNumber,"battlEye_friendlyLogging") isEqualTo 1) then {
        money_log = format ["robbed £%1 from %2. Bank Balance: £%3  On Hand Balance: £%4",[_cash] call life_fnc_numberText,_victim,[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    } else {
        money_log = format ["%1 - %2 robbed £%3 from %4. Bank Balance: £%5  On Hand Balance: £%6",profileName,(getPlayerUID player),[_cash] call life_fnc_numberText,_victim,[BANK] call life_fnc_numberText,[CASH] call life_fnc_numberText];
    };
    publicVariableServer "money_log";
};
