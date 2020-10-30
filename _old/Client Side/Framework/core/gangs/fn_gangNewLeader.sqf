#include "..\..\script_macros.hpp"
/*
    File: fn_gangNewLeader.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Something about being a quitter.
*/
private ["_unit","_unitID","_members","_action","_index"];
disableSerialization;

if ((lbCurSel 2621) isEqualTo -1) exitWith {hint "You need to select a person first!"};
_unit = call compile format ["%1",CONTROL_DATA(2621)];

if (isNull _unit) exitWith {}; //Bad unit?
if (_unit == player) exitWith {hint "You are already the leader!"};

_action = [
    format ["You are about to transfer leadership over to %1 &lt;br/&gt;By transferring leadership you will no longer be in control of the group unless ownership is transferred back.",_unit getVariable ["realname",name _unit]],
    "Transfer Group Leadership",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    _unitID = getPlayerUID _unit;
    if (_unitID isEqualTo "") exitWith {hint "Bad UID?";}; //Unlikely?
    group player setVariable ["gang_owner",_unitID,true];
    group player selectLeader _unit;
    [_unit,group player] remoteExec ["TON_fnc_clientGangLeader",_unit]; //Boot that bitch!

    if (life_HC_isActive) then {
        [3,group player] remoteExec ["HC_fnc_updateGang",HC_Life]; //Update the database.
    } else {
        [3,group player] remoteExec ["TON_fnc_updateGang",RSERV]; //Update the database.
    };

} else {
    hint "Transfer of leadership cancelled.";
};
[] call life_fnc_gangMenu;
