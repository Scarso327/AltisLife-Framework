#include "..\..\script_macros.hpp"
/*
    File: fn_knockedOut.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Starts and monitors the knocked out state.
*/
params [
    ["_target",objNull,[objNull]],
    ["_who","",[""]]
];

if (isNull _target) exitWith {};
if !(_target isEqualTo player) exitWith {};
if (_who isEqualTo "") exitWith {};

life_isknocked = true;

if (!(player getVariable ["Escorting",false])) then {
    detach player;
};

disableUserInput true;
player setUnconscious true;
player setVariable ["isKnckedOut", life_isknocked, true];

titleText[format [localize "STR_Civ_KnockedOut",_who],"PLAIN"];

sleep 15;

life_isknocked = false;
player setUnconscious false;
player setVariable ["isKnckedOut", life_isknocked, true];
disableUserInput false;

player setVariable ["robbed",false,true];

player playMoveNow "amovppnemstpsraswrfldnon";