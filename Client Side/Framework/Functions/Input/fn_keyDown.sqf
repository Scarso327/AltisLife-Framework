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

_disabledKeys append (actionKeys "tacticalView"); // Disable tactical view...

if ([player] call ULP_fnc_isRestrained || { [player] call ULP_fnc_isSurrendered }) then {
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
    _handled = true;

    if (_code in (actionKeys "pushToTalk")) then { _handled = false; };

    private _viewToggle = ACT_KEY("personView", NUMENTER);

    // Available Incapacitated Inputs...
    switch (_code) do {
        case _viewToggle: { _handled = false };
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
                private _currentWeapon = currentWeapon player;

                if !(_currentWeapon isEqualTo "") exitWith {
                    ULP_Holsted = _currentWeapon;

                    player action ["SwitchWeapon", player, player, 100];
                    player switchCamera cameraView;
                };

                if (ULP_Holsted in [(primaryWeapon player), (handgunWeapon player)]) then {
                    player selectWeapon ULP_Holsted;
                    ULP_Holsted = "";
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
                    [_object, player, true] call ULP_fnc_restrain;
                };
                _handled = true;
            };
        };

        case F: {
            if (!_alt && { !(isNull (objectParent player)) }) then {
                private _veh = vehicle player;
                private _vehSiren = missionConfigFile >> "CfgVehicles" >> (typeOf _veh) >> "Textures" >> (_veh getVariable ["texture", ""]) >> "Siren";
                private _sirens = getArray (_vehSiren >> "SFX");
                    
                // None of this can happen without them
                if (_sirens isEqualTo []) exitWith {};

                if (isClass _vehSiren && { (driver _veh) isEqualTo player }) then {
                    private _timeout = ULP_sirenDelay;

                    if (isNull (_veh getVariable ["siren", objNull])) then {
                        if (_shift && { isNil "_timeout" || { time > _timeout } }) then {
                            titleText["Sirens On", "PLAIN"];
                            [_veh, _sirens] call ULP_fnc_vehicleSiren;
                        };
                    } else {
                        if (_ctrlKey && { !_shift } && { isNil "_timeout" || { time > _timeout } }) exitWith {
                            ULP_sirenDelay = time + 1;
                            
                            _veh setVariable ["selected_siren", (((_veh getVariable ["selected_siren", 0]) + 1) % (count _sirens))];
                            [_veh, _sirens] call ULP_fnc_vehicleSiren;
                        };

                        if (_shift) then {
                            ULP_sirenDelay = time + 2;

                            titleText["Sirens Off", "PLAIN"];
                            [_veh, [], false] call ULP_fnc_vehicleSiren;
                        };
                    };

                    _handled = true;
                };
            };
        };

        case L: {
            if (_shift && { !_alt } && { !_ctrlKey } && { !(isNull (objectParent player)) }) then {
                private _veh = vehicle player;
                private _vehLights = missionConfigFile >> "CfgVehicles" >> (typeOf _veh) >> "Textures" >> (_veh getVariable ["texture", ""]) >> "Lights";

                if (isClass _vehLights && { isArray (_vehLights >> "leftPos") } && { isArray (_vehLights >> "rightPos") } && { (driver _veh) isEqualTo player }) then {
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
            if (!_alt && { !_ctrlKey } && { !dialog } && { !(player call ULP_fnc_isRestrained) } && { !(player call ULP_fnc_isKnocked) } && { !(player call ULP_fnc_isSurrendered) } && { !([] call ULP_UI_fnc_isProgress) }) then {
                [] call ULP_fnc_openTablet;
            };
        };

        case U: {
            if (!_ctrlKey && { !_alt }) then {
                private _veh = ([cursorObject, (vehicle player)] select !(isNull (objectParent player)));

                if (ULP_Ability_Cooldown > time) exitWith {};
                
                if ((player distance _veh) <= 10 && { _veh in ULP_Keys || _veh in ULP_Houses || (!([player] call ULP_fnc_isRestrained) && (_veh isEqualTo (vehicle player))) }) then {
                    if ([_veh] call ULP_fnc_isHouse) then {
                        private _door = [_veh] call ULP_fnc_getNearestDoor;
                        if (_door > -1) then {
                            if ((_veh getVariable [format ["bis_disabled_Door_%1",_door], 0]) isEqualTo 0) then {
                                _veh setVariable [format ["bis_disabled_Door_%1",_door], 1, true];
                                _veh animate [format["door_%1_rot",_door],0];

                                systemChat "You've locked this door.";
                            } else {
                                _veh setVariable [format ["bis_disabled_Door_%1", _door], 0, true];
                                _veh animate [format["door_%1_rot", _door], 1];

                                systemChat "You've unlocked this door.";
                            };
                        };

                        _handled = true;
                    } else {
                        if ((locked _veh) isEqualTo 2) then {
                            [_veh, 0] remoteExecCall ["ULP_fnc_lock", _veh];
                            [_veh, "unlockCarSound", 50, 1] remoteExecCall ["ULP_fnc_say3D"];

                            systemChat "You've unlocked this vehicle.";
                        } else {
                            [_veh, 2] remoteExecCall ["ULP_fnc_lock", _veh];
                            [_veh, "lockCarSound", 50, 1] remoteExecCall ["ULP_fnc_say3D"];

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