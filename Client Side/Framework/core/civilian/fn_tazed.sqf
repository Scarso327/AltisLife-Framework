#include "..\..\script_macros.hpp"
/*
    File: fn_tazed.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Starts the tazed animation and broadcasts out what it needs to.
*/
params [
    ["_unit",objNull,[objNull]],
    ["_shooter",objNull,[objNull]]
];

if (isNull _unit || isNull _shooter) exitWith {player allowDamage true; life_istazed = false;};

if (_shooter isKindOf "CAManBase" && (alive player && !(isDowned(player)))) then {
    if (!life_istazed) then {
        life_istazed = true;

        if (!(player getVariable ["Escorting",false])) then {
            detach player;
        };

        disableUserInput true;
        player setUnconscious true;
        player setVariable ["isTazed", life_istazed, true];

        [0,"%1 was tased by %2.",true,[profileName, _shooter getVariable ["realname",name _shooter]]] remoteExecCall ["life_fnc_broadcast",RCLIENT];

        sleep 10;

        life_istazed = false;
        player setUnconscious false;
        player setVariable ["isTazed", life_istazed, true];
        disableUserInput false;

        player playMoveNow "amovppnemstpsraswrfldnon";
    };
} else {
    _unit allowDamage true;
    life_istazed = false;
};
