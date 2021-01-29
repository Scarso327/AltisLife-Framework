/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_keyDown";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

private _handled = false;
private _disabledKeys = [];
private _interruptKeys = [W, A, S, D];

_disabledKeys append (actionKeys "tacticalView"); // Disable tactical view...

if ([player] call ULP_fnc_isRestrained || { [player] call ULP_fnc_isSurrended }) then {
    _disabledKeys append (actionKeys "GetOver");
    _disabledKeys append (actionKeys "GetIn");
    _disabledKeys append (actionKeys "ReloadMagazine");
    _disabledKeys append (actionKeys "Fire");
    _disabledKeys append (actionKeys "SitDown");
    _disabledKeys append (actionKeys "Throw");
    _disabledKeys append [Q, E];
};

if (_code in _disabledKeys) then { _handled = true };

if (isDowned(player)) then { 
    // Incapacitated Inputs...
    switch (_code) do {
        case ESC: { _handled = true };
    };
} else {
    switch (_code) do {
        case B: {
            if (_shift && { !_ctrlKey }) then {
                if (ULP_Ability_Cooldown < time) then {
                    [!([player] call ULP_fnc_isSurrendered)] call ULP_fnc_surrender;
                    ULP_Ability_Cooldown = time + 1;
                };

                _handled = true;
            };
        };

        case H: {
            if (_shift && { !_ctrlKey }) then {
                if (ULP_Holsted isEqualTo "" && { !((currentWeapon player) isEqualTo "") }) then {
                    ULP_Holsted = (currentWeapon player);
                    player action ["SwitchWeapon", player, player, 100];
                    player switchCamera cameraView;
                } else {
                    if (ULP_Holsted in [(primaryWeapon player), (handgunWeapon player)]) then {
                        player selectWeapon ULP_Holsted;
                        ULP_Holsted = "";
                    };
                };
            };
        };

        case R: {
            private _object = cursorObject;

            if (_shift && { [_object] call ULP_fnc_canRestrain }) then {
                [_object, !([_object] call ULP_fnc_isRestrained)] call ULP_fnc_restrain;
                _handled = true;
            };
        };

        case Y: {
            if (!_alt && { !_ctrlKey } && { !dialog } && { !(player call ULP_fnc_isRestrained) } && { !life_action_inUse }) then {
                [] call life_fnc_p_openMenu;
            };
        };

        case U: {
            if (!_ctrlKey && { !_alt }) then {
                private _veh = ([cursorObject, (vehicle player)] select !(isNull (objectParent player)));

                if (ULP_Ability_Cooldown > time) exitWith {};

                if (_veh in ULP_Keys && { (player distance _veh) <= 10 }) then {
                    if (_veh isKindOf "House_F") then {
                        // TODO : Door Unlocking...
                    } else {
                        if ((locked _veh) isEqualTo 2) then {
                            _veh lock 0;
                            systemChat "You've unlocked this vehicle.";
                            [_veh, "unlockCarSound", 50, 1] remoteExec ["life_fnc_say3D", RANY];
                        } else {
                            _veh lock 2;
                            systemChat "You've locked this vehicle.";
                            [_veh, "lockCarSound", 50, 1] remoteExec ["life_fnc_say3D", RANY];
                        };
                    };

                    ULP_Ability_Cooldown = time + 1;
                };
            };
        };
    };
};

_handled