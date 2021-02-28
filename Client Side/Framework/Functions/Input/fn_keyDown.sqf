/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
#define ACT_KEY(name, default) [(actionKeys name) select 0, default] select (actionKeys name isEqualTo [])
scopeName "fn_keyDown";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

private _handled = false;
private _disabledKeys = [];

private _interactionKey = ACT_KEY("User10", 219);

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

if ([] call ULP_UI_fnc_isProgress) then {
    if (_code isEqualTo ESC) exitWith {
        [(["RscProgress"] call ULP_UI_fnc_getLayer), false] call ULP_UI_fnc_endProgress;
        true breakOut "fn_keyDown";
    };
};

if (isDowned(player)) then { 
    // Incapacitated Inputs...
    switch (_code) do {
        case ESC: { _handled = true };
    };
} else {
    switch (_code) do {
        case _interactionKey: {
            if !([] call ULP_UI_fnc_isProgress) then {
                _this call ULP_fnc_actionKeyDown;
                _handled = true;
            };
        };

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

        case G: {
            if (_shift) then {
                if !((currentWeapon player) in getArray(missionConfigFile >> "CfgSettings" >> "doesntThreaten")) then {
                    [cursorObject] call ULP_fnc_knockOut; // Script does checks...
                };
                _handled = true;
            };
        };

        case R: {
            private _object = cursorObject;

            if (_shift) then {
                if ([_object] call ULP_fnc_canRestrain) then {
                    [_object, !([_object] call ULP_fnc_isRestrained)] call ULP_fnc_restrain;
                };
                _handled = true;
            };
        };

        case Y: {
            if (!_alt && { !_ctrlKey } && { !dialog } && { !(player call ULP_fnc_isRestrained) } && { !([] call ULP_UI_fnc_isProgress) }) then {
                [] call ULP_fnc_openTablet;
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