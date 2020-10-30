#include "..\..\script_macros.hpp"
/*
    File: fn_postBail.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Called when the player attempts to post bail.
    Needs to be revised.
*/
private ["_unit"];
_unit = param [1,objNull,[objNull]];
if (life_bail_paid) exitWith {};
if (isNil "life_bail_amount") then {life_bail_amount = 3500;};
if (!life_canpay_bail) exitWith {hint "You must wait at least 3 minutes before paying a bail."};
if (BANK < life_bail_amount) exitWith {hint format ["You do not have £%1 in your bank account to pay bail.",life_bail_amount];};

BANK = BANK - life_bail_amount;
life_bail_paid = true;
[1] call SOCK_fnc_updatePartial;
[0,"%1 has posted bail!",true,[profileName]] remoteExecCall ["life_fnc_broadcast",RCLIENT];