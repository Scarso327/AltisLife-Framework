#include "..\..\script_macros.hpp"
/*
    File: fn_onFired.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Handles various different ammo types being fired.
*/
private ["_ammoType","_projectile"];
_ammoType = _this select 4;
_projectile = _this select 6;

if (_ammoType in ["GrenadeHand_stone","UGL_FlareCIR_F"]) then {
    _projectile spawn {
        private "_position";
        while {!isNull _this} do {
            _position = ASLtoATL (visiblePositionASL _this);
            sleep 0.1;
        };
        [_position] remoteExec ["life_fnc_flashbang",RCLIENT];
    };
};

if (_weapon == ["hgun_Pistol_heavy_01_F", "hgun_Pistol_heavy_01_MRD_F", "hgun_Pistol_heavy_01_snds_F") then {_delayTime = 0.5;} else {_delayTime = 0.75;};
if (_weapon == "hgun_Pistol_heavy_01_F" || _weapon == "hgun_Pistol_heavy_01_MRD_F" || _weapon == "hgun_Pistol_heavy_01_snds_F") then { 
    [] spawn {
        _time = time;
        while {time - _time < 0.5} do {
            player setWeaponReloadingTime [player, currentWeapon player, 0.25];
        };
    };
};