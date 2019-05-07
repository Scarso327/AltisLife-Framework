#include "..\..\script_macros.hpp"
/*
    File: fn_gangInvite.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Prompts the player about an invite.
*/
private ["_action","_grpMembers"];
params [
    ["_name","",[""]],
    ["_group",grpNull,[grpNull]]
];

if (_name isEqualTo "" || isNull _group) exitWith {}; //Fail horn anyone?
if (!isNil {(group player) getVariable "gang_name"}) exitWith {hint "You are already in a group.";};

_gangName = _group getVariable "gang_name";
_action = [
    format ["%1 has invited you to a group called %2<br/>If you accept the invitation you will be a part of their gang and will have access to the group funds and controlled hideouts.",_name,_gangName],
    "Group Invitation",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    [player] join _group;

    FF_gangID = _group getVariable "gang_id";
    [9] call SOCK_fnc_updatePartial;
    player setVariable ["gangID", FF_gangID, true];
} else {
    _members = _members - [[(player getVariable ["realname", name player]), (getPlayerUID player)]];
    group player setVariable ["gang_members",_members,true];
};