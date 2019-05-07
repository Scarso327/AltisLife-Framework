#include "..\..\script_macros.hpp"
/*
    File: fn_gangLeave.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    32 hours later...
*/
private ["_unitID ","_members"];
if (getPlayerUID player isEqualTo (group player getVariable "gang_owner")) exitWith {hint "You cannot leave the group without appointing a new leader first!"};

_unitID = getPlayerUID player;
_members = group player getVariable "gang_members";
if (isNil "_members") exitWith {};
if (!(_members isEqualType [])) exitWith {};

_members = _members - [[(player getVariable ["realname", name player]), (getPlayerUID player)]];
group player setVariable ["gang_members",_members,true];

[player,group player] remoteExec ["TON_fnc_clientGangLeft",player];

closeDialog 0;
FF_gangID = -1;
[9] call SOCK_fnc_updatePartial;
player setVariable ["gangID", FF_gangID, true];