#include "..\..\script_macros.hpp"
/*
    File: fn_gangInvitePlayer.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Invites the player into the gang.
*/
private "_unit";
disableSerialization;

if ((lbCurSel 2632) isEqualTo -1) exitWith {hint "You need to select a person to invite!"};
_unit = call compile format ["%1",CONTROL_DATA(2632)];

if (isNull _unit) exitWith {}; //Bad unit?
if (_unit isEqualTo player) exitWith {hint localize "STR_GNOTF_InviteSelf"};
if (isDowned(_x) && { (_x getVariable ["isTazed", false]) } && { (_x getVariable ["isKnckedOut", false]) }) exitWith {};
if (!isNil {(group _unit) getVariable "gang_name"}) exitWith {hint "This person is already in a group.";}; //Added

if (count(group player getVariable ["gang_members",8]) == (group player getVariable ["gang_maxMembers",8])) exitWith {hint "Your group has reached its maximum allowed slots, please upgrade your group slot limit."};

_action = [
    format [localize "You are about to invite %1 to your group, if they accept the invite they will have access to the group's funds.",_unit getVariable ["realname",name _unit]],
    "Group Invitation",
    "Yes",
    "No"
] call BIS_fnc_guiMessage;

if (_action) then {
    [profileName,group player] remoteExec ["life_fnc_gangInvite",_unit];
    _members = group player getVariable "gang_members";
    _members pushBack getPlayerUID _unit;
    group player setVariable ["gang_members",_members,true];
    hint format ["You have sent an invite to %1",_unit getVariable ["realname",name _unit]];
} else {
    hint "Invitation Cancelled";
};