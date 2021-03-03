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

        case F: {
            if (_shift && { !_alt } && { !_ctrlKey } && { !(isNull (objectParent player)) }) then {
                private _veh = vehicle player;
                private _vehSiren = missionConfigFile >> "CfgVehicles" >> (typeOf _veh) >> "Textures" >> (_veh getVariable ["texture", ""]) >> "Siren";

                if (isClass _vehSiren && { (driver _veh) isEqualTo player }) then {
                    if (isNull (_veh getVariable ["siren", objNull])) then {
                        private _timeout = ULP_sirenDelay;

                        if (isNil "_timeout" || { time > _timeout }) then {
                            private _sirens = getArray (_vehSiren >> "SFX");

                            if !(_sirens isEqualTo []) then {
                                titleText["Sirens On", "PLAIN"];
                                [_veh, _sirens select 0] call ULP_fnc_vehicleSiren;
                            };
                        };
                    } else {
                        ULP_sirenDelay = time + 2;

                        titleText["Sirens Off", "PLAIN"];
                        [_veh, "", false] call ULP_fnc_vehicleSiren;
                    };

                    _handled = true;
                };
            };
        };

        case L: {
            if (_shift && { !_alt } && { !_ctrlKey } && { !(isNull (objectParent player)) }) then {
                private _veh = vehicle player;
                private _vehLights = missionConfigFile >> "CfgVehicles" >> (typeOf _veh) >> "Textures" >> (_veh getVariable ["texture", ""]) >> "Lights";

                if (isClass _vehLights && { (driver _veh) isEqualTo player }) then {
                    if (isNull (_veh getVariable ["lightLoop", scriptNull])) then {
                        private _timeout = ULP_lightDelay;

                        if (isNil "_timeout" || { time > _timeout }) then {
                            titleText["Lights On", "PLAIN"];
                            [_veh, 
                                [getArray(_vehLights >> "leftPos"), getArray(_vehLights >> "leftColour")],
                                [getArray(_vehLights >> "rightPos"), getArray(_vehLights >> "rightColour")]
                            ] remoteExecCall ["ULP_fnc_vehicleLights"];
                        };
                    } else {
                        ULP_lightDelay = time + 2;

                        titleText["Lights Off", "PLAIN"];
                        [_veh, [], [], false] remoteExecCall ["ULP_fnc_vehicleLights"];
                    };

                    _handled = true;
                };
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
                            [_veh, 0] remoteExec ["lock", _veh];
                            [_veh, ["unlockCarSound", 50, 1]] remoteExec ["say3D"];

                            systemChat "You've unlocked this vehicle.";
                        } else {
                            [_veh, 2] remoteExec ["lock", _veh];
                            [_veh, ["lockCarSound", 50, 1]] remoteExec ["say3D"];

                            systemChat "You've locked this vehicle.";
                        };

                        _handled = true;
                    };

                    ULP_Ability_Cooldown = time + 1;
                };
            };
        };
    };
};

_handled