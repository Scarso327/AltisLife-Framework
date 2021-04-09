/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
#define ACT_KEY(name, default) [(actionKeys name) select 0, default] select (actionKeys name isEqualTo [])
scopeName "fn_keyUp";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

private _handled = false;

private _seatKey = ACT_KEY("User1", B);
private _interactionKey = ACT_KEY("User10", LWINDOWS);

switch (_code) do {
    if (isDowned(player)) then {
        _handled = true;
        case F: { if (_shift && { missionNamespace getVariable ["ULP_CanRespawn", false] }) then { player SetDammage 1; } }; // Respawn (Shift + F)...
		case SPACE: {  }; // Request Medic (Space, TODO)
    };

    case _interactionKey: {
        if !([] call ULP_UI_fnc_isProgress) then {
            _this call ULP_fnc_actionKeyDown;
            _handled = true;
        };
    };

    case _seatKey: {
        if (!(isNull (objectParent player)) && { (vehicle player) isKindOf "LandVehicle" }) then {
            player setVariable["seatbelt", !(player getVariable["seatbelt", false])];
        };
    };

    case J: {
        if (_shift && { !(isDowned(player)) } && { [player] call ULP_fnc_isRestrained } && { (["PanicButton"] call ULP_fnc_hasItem) > 0 }) then {
            [] call ULP_fnc_panic;
        };
    };

    case T: {
        if !(_shift && { _ctrlKey } && { _alt } && { dialog }) then {
            if (isNull (objectParent player)) then {
                private _container = cursorObject;

                if ((player distance _container) < 5) then {
                    _handled = [_container] call ULP_fnc_openInventory;
                };
            } else {
                _handled = [vehicle player] call ULP_fnc_openInventory;
            };
        };
    };

    case O: {
        if (_shift && { !_ctrlKey } && { !_alt }) then {
            ULP_FadeSound = !ULP_FadeSound;
            0 fadeSound ([1, ["EffectsFade", "Audio"] call ULP_fnc_getOption] select (ULP_FadeSound));
            0 fadeMusic ([1, ["MusicFade", "Audio"] call ULP_fnc_getOption] select (ULP_FadeSound));

            hint format["You %1 your earplugs", ["remove", "put in"] select (ULP_FadeSound)];
        };
    };

    case F1: {
        if ([] call ULP_fnc_isStaff && { _shift } && { !_ctrlKey } && { !_alt }) then {
            [] call ULP_fnc_toggleAdminGear;
        };
    };

    case F2: {
        if ([] call ULP_fnc_isStaff && { ["Camera", false] call ULP_fnc_checkPower } && { _shift } && { !_ctrlKey } && { !_alt }) then {
            (findDisplay 46) createDisplay "DisplayAdmin";
            _handled = true;
        };
    };

    case F3: {
        if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { ["Invis", false] call ULP_fnc_checkPower } && { _shift } && { !_ctrlKey } && { !_alt }) then {
            if (time < (player getVariable ["admin_invis_cooldown", 0])) exitWith {
                hint "You've recently changed your visibility, please wait before trying again...";
                false
            };
            player setVariable ["admin_invis_cooldown", time + 2];

            [player, !(isObjectHidden player)] remoteExecCall ["ULP_SRV_fnc_hidePlayer", RSERV];
            [getPlayerUID player, "Admin", ["AdminInvisibility", serverTime, []]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
        };
    };
};

_handled