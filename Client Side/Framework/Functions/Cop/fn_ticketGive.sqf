#include "..\..\script_macros.hpp"
/*
    File: fn_ticketGive.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Gives a ticket to the targeted player.
*/
if (isNil "life_ticket_unit") exitWith {hint "Person to ticket is nil"};
if (isNull life_ticket_unit) exitWith {hint "Person to ticket doesn't exist."};

private _val = ctrlText 2652;

if (!([_val] call TON_fnc_isnumber)) exitWith {hint "You didn't enter actual number."};
if ((parseNumber _val) > 200000) exitWith {hint "Tickets can not be more than £200,000!"};

[0,"%1 gave a ticket of £%2 to %3",true,[profileName,[(parseNumber _val)] call life_fnc_numberText,life_ticket_unit getVariable ["realname",name life_ticket_unit]]] remoteExecCall ["life_fnc_broadcast",RCLIENT];
[player,(parseNumber _val)] remoteExec ["life_fnc_ticketPrompt",life_ticket_unit];
closeDialog 0;
