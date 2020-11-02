#include "..\..\script_macros.hpp"
/*
    File: fn_freezePlayer.sqf
    Author: ColinM9991

    Description:
    Freezes selected player.
*/
private ["_admin"];
_admin = [_this,0,objNull,[objNull]] call BIS_fnc_param;

if (life_frozen) then {
    [1,format ["You have enabled %1's input.",profileName]] remoteExecCall ["life_fnc_broadcast",_admin];
    disableUserInput false;
    life_frozen = false;
} else {
    [1,format ["You have disabled %1's input.",profileName]] remoteExecCall ["life_fnc_broadcast",_admin];
    disableUserInput true;
    life_frozen = true;
};
