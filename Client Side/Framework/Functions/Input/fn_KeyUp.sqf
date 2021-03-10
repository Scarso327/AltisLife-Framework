/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_keyUp";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

private _handled = false;

switch (_code) do {
    if (isDowned(player)) then {
        case F: { if (_shift && { missionNamespace getVariable ["ULP_CanRespawn", false] }) then { player SetDammage 1; _handled = true; } }; // Respawn (Shift + F)...
		case SPACE: {  }; // Request Medic (Space, TODO)
    };

    case RWINDOWS: {
        if !(_shift && { _ctrl } && { _alt }) then {
            ULP_FadeSound = !ULP_FadeSound;
            0 fadeSound ([1, ["EffectsFade", "Audio"] call ULP_fnc_getOption] select (ULP_FadeSound));
            0 fadeMusic ([1, ["MusicFade", "Audio"] call ULP_fnc_getOption] select (ULP_FadeSound));

            hint format["You %1 your earplugs", ["remove", "put in"] select (ULP_FadeSound)];
        };
    };
};

_handled