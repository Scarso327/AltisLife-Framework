#include "..\..\script_macros.hpp"
/*
    File: fn_gangDisband.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Prompts the user about disbanding the gang and if the user accepts the gang will be
    disbanded and removed from the database.
*/
private "_action";
_action = [
    localize "You are about to disband the organisation, by disbanding the organisation it will be removed from the database and the organisation will be dropped. &lt;br/&gt;&lt;br/&gt;Are you sure you want to disband the organisation? You will not be refunded the price for creating it.",
    "Disband Group",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    hint "Disbanding the group...";

    if (life_HC_isActive) then {
        [group player] remoteExec ["HC_fnc_removeGang",HC_Life];
    } else {
        [group player] remoteExec ["TON_fnc_removeGang",RSERV];
    };

} else {
    hint "Disbanding cancelled";
};