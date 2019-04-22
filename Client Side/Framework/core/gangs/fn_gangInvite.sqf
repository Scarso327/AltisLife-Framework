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
    format [localize "%1 has invited you to a group called %2&lt;br/&gt;If you accept the invitation you will be a part of their gang and will have access to the group funds and controlled hideouts.",_name,_gangName],
    "Group Invitation",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    [player] join _group;

    if (life_HC_isActive) then {
        [4,_group] remoteExecCall ["HC_fnc_updateGang",HC_Life];
    } else {
        [4,_group] remoteExecCall ["TON_fnc_updateGang",RSERV];
    };

} else {
    _grpMembers = _group getVariable "gang_members";
    _grpMembers = _grpMembers - [getPlayerUID player];
    _group setVariable ["gang_members",_grpMembers,true];

    if (life_HC_isActive) then {
        [4,_group] remoteExecCall ["HC_fnc_updateGang",HC_Life];
    } else {
        [4,_group] remoteExecCall ["TON_fnc_updateGang",RSERV];
    };

};
