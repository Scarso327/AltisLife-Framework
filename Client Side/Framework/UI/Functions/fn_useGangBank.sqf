#include "..\..\script_macros.hpp"
/*
    File: fn_gangWithdraw.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Withdraws money from the gang bank.
*/
params [
    ["_deposit",false,[false]]
];

private _value = parseNumber(ctrlText 2702);
private _gFund = GANG_FUNDS;
if ((time - life_action_delay) < 0.5) exitWith {hint "You're doing it too fast!"};

//Series of stupid checks
if (isNil {(group player) getVariable "gang_name"}) exitWith {hint "You are not in a group."};
if (_value > 999999) exitWith {hint "You can't withdraw more then £999,999.";};
if (_value < 1) exitWith {};
if (!([str(_value)] call TON_fnc_isnumber)) exitWith {hint "The amount entered isn't a numeric value."};
if (_deposit && _value > CASH) exitWith {hint "You do not have that much money on you."};
if (!_deposit && _value > _gFund) exitWith {hint "You don't have that much in your group bank account!"};

if (_deposit) then {
    CASH = CASH - _value;
    [] call life_fnc_atmMenu;
};

if (life_HC_isActive) then {
    [1,group player,_deposit,_value,player,CASH] remoteExecCall ["HC_fnc_updateGang",HC_Life]; //Update the database.
} else {
    [1,group player,_deposit,_value,player,CASH] remoteExecCall ["TON_fnc_updateGang",RSERV]; //Update the database.
};

life_action_delay = time;