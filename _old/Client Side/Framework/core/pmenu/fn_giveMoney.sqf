#include "..\..\script_macros.hpp"
/*
    File: fn_giveMoney.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Gives the selected amount of money to the selected player.
*/
if !(params[
    ["_unit", objNull, [objNull]]
]) exitWith {};

private _amount = ctrlText 7201;

ctrlEnable[7202,false];

if (isNil "_unit") exitWith {ctrlEnable[7202,true];};
if (_unit == player) exitWith {ctrlEnable[7202,true];};
if (isNull _unit) exitWith {ctrlEnable[7202,true];};

//A series of checks *ugh*
if (!life_use_atm) exitWith {hint "You recently robbed the bank! You can't give money away just yet."; ctrlEnable[7202,true];};
if (!([_amount] call TON_fnc_isnumber)) exitWith {hint "You didn't enter an actual number format."; ctrlEnable[7202,true];};
if (parseNumber(_amount) <= 0) exitWith {hint localize "STR_NOTF_enterAmount"; ctrlEnable[7202,true];};
if (parseNumber(_amount) > CASH) exitWith {hint "You don't have that much to give!"; ctrlEnable[7202,true];};
if (isNull _unit) exitWith {ctrlEnable[7202,true];};
if (isNil "_unit") exitWith {ctrlEnable[7202,true]; hint "The selected player is not within range.";};

hint format ["You gave £%1 to %2.",[(parseNumber(_amount))] call life_fnc_numberText,_unit getVariable ["realname",name _unit]];
CASH = CASH - (parseNumber(_amount));
[0] call SOCK_fnc_updatePartial;

[_unit,_amount,player] remoteExecCall ["life_fnc_receiveMoney",_unit];

closeDialog 0;