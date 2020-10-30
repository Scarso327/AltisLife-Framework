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

// Blurry effect...
_effectBlur = ppEffectCreate ["DynamicBlur", 300];
_effectBlur ppEffectEnable true;
_effectBlur ppEffectAdjust [2.5];
_effectBlur ppEffectCommit 3;
FF_effects pushBack [_effectBlur];

disableUserInput true;
player setUnconscious true;
player setVariable ["isKnockedOut", life_isknocked, true];

titleText[format ["%1 has knocked you out.",_who],"PLAIN"];

sleep 15;

life_isknocked = false;
player setUnconscious false;
player setVariable ["isKnockedOut", life_isknocked, true];
disableUserInput false;

player setVariable ["robbed",false,true];

{ppEffectDestroy _x} forEach FF_effects; // Remove Effects...

player playMoveNow "amovppnemstpsraswrfldnon";