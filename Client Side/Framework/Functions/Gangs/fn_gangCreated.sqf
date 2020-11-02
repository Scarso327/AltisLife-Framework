#include "..\..\script_macros.hpp"
/*
    File: fn_gangCreated.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Tells the player that the gang is created and throws him into it.
*/
private "_group";
life_action_gangInUse = nil;

if (BANK < (LIFE_SETTINGS(getNumber,"gang_price"))) exitWith {
    hint format ["You do not have enough money in your bank account.\n\nYou lack: £%1",[((LIFE_SETTINGS(getNumber,"gang_price"))-BANK)] call life_fnc_numberText];
    {group player setVariable [_x,nil,true];} forEach ["gang_id","gang_owner","gang_name","gang_members","gang_maxmembers","gang_bank"];
};

BANK = BANK - LIFE_SETTINGS(getNumber,"gang_price");
[1] call SOCK_fnc_updatePartial;

hint format ["You have created the group %1 for £%2",(group player) getVariable "gang_name",[(LIFE_SETTINGS(getNumber,"gang_price"))] call life_fnc_numberText];