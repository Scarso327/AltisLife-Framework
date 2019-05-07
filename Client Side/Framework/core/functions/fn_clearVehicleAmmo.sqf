#include "..\..\script_macros.hpp"
/*
    File: fn_clearVehicleAmmo.sqf
    Author: Bryan "Tonic" Boardwine

    Description:
    Clears the vehicle of ammo types that we don't want.

    Syntax: _vehicle removeMagazinesTurret [magazineName, turretPath]
    Documentation: https://community.bistudio.com/wiki/removeMagazinesTurret
*/
private ["_vehicle","_veh"];
_vehicle = [_this,0,objNull,[objNull]] call BIS_fnc_param;
if (isNull _vehicle) exitWith {};
_veh = typeOf _vehicle;

if (_veh isEqualTo "B_Boat_Armed_01_minigun_F") then {
    _vehicle removeMagazinesTurret ["200Rnd_40mm_G_belt",[0]];
};

if (_veh isEqualTo "B_APC_Wheeled_01_cannon_F") then {
    _vehicle removeMagazinesTurret ["60Rnd_40mm_GPR_Tracer_Red_shells",[0]];
    _vehicle removeMagazinesTurret ["40Rnd_40mm_APFSDS_Tracer_Red_shells",[0]];
};

if (_veh isEqualTo "O_Heli_Attack_02_black_F") then {
    _vehicle removeMagazinesTurret ["250Rnd_30mm_APDS_shells",[0]];
    _vehicle removeMagazinesTurret ["8Rnd_LG_scalpel",[0]];
    _vehicle removeMagazinesTurret ["38Rnd_80mm_rockets",[0]];
};

if (_veh isEqualTo "B_Heli_Transport_01_F") then {
    _vehicle removeMagazinesTurret ["2000Rnd_65x39_Belt_Tracer_Red",[1]];
    _vehicle removeMagazinesTurret ["2000Rnd_65x39_Belt_Tracer_Red",[2]];
};

// Planes...
if (_veh isEqualTo "B_Plane_Fighter_01_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter01_Gun20mm_AA_x450",[0]];
    _vehicle removeMagazinesTurret ["240Rnd_CMFlare_Chaff_Magazine",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "B_Plane_Fighter_01_Stealth_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter01_Gun20mm_AA_x450",[0]];
    _vehicle removeMagazinesTurret ["240Rnd_CMFlare_Chaff_Magazine",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "I_Plane_Fighter_04_F") exitWith {
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
};

if (_veh isEqualTo "O_Plane_Fighter_02_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter02_Gun30mm_AA_x180",[0]];
    _vehicle removeMagazinesTurret ["240Rnd_CMFlare_Chaff_Magazine",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "O_Plane_Fighter_02_Stealth_F") exitWith {
    _vehicle removeMagazinesTurret ["magazine_Fighter02_Gun30mm_AA_x180",[0]];
    _vehicle removeMagazinesTurret ["240Rnd_CMFlare_Chaff_Magazine",[0]];
    _vehicle setVehicleAmmo 0;
};

if (_veh isEqualTo "I_Plane_Fighter_03_AA_F") exitWith {
    _vehicle removeMagazinesTurret ["300Rnd_20mm_shells",[0]];
    _vehicle removeMagazinesTurret ["2Rnd_AAA_missiles",[0]];
    _vehicle removeMagazinesTurret ["4Rnd_GAA_missiles",[0]];
    _vehicle removeWeaponTurret ["Twin_Cannon_20mm",[-1]];
    _vehicle removeWeaponTurret ["missiles_Zephyr",[-1]];
    _vehicle removeWeaponTurret ["missiles_ASRAAM",[-1]];
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
};

if (_veh isEqualTo "O_Plane_CAS_02_F") exitWith {
    _vehicle removeMagazinesTurret ["500Rnd_Cannon_30mm_Plane_CAS_02_F",[0]];
    _vehicle removeMagazinesTurret ["2Rnd_Missile_AA_03_F",[0]];
    _vehicle removeMagazinesTurret ["4Rnd_Missile_AGM_01_F",[0]];
    _vehicle removeMagazinesTurret ["2Rnd_Bomb_03_F",[0]];
    _vehicle removeMagazinesTurret ["20Rnd_Rocket_03_HE_F",[0]];
    _vehicle removeMagazinesTurret ["20Rnd_Rocket_03_AP_F",[0]];
    _vehicle removeWeaponTurret ["Cannon_30mm_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Missile_AA_03_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Missile_AGM_01_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Rocket_03_HE_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Rocket_03_AP_Plane_CAS_02_F",[-1]];
    _vehicle removeWeaponTurret ["Bomb_03_Plane_CAS_02_F",[-1]];
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
};

if (_veh isEqualTo "B_Plane_CAS_01_F") exitWith {
    _vehicle removeMagazinesTurret ["Gatling_30mm_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Missile_AA_04_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Missile_AGM_02_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Rocket_04_HE_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Rocket_04_AP_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["Bomb_04_Plane_CAS_01_F",[0]];
    _vehicle removeMagazinesTurret ["CMFlareLauncher",[0]];
    _vehicle setVehicleAmmo 0;
    _vehicle animate ["HideTurret",1];
};

if (_veh isEqualTo "I_Plane_Fighter_03_dynamicLoadout_F") exitWith {
    _vehicle setVehicleAmmo 0;
    _vehicle setVehicleAmmoDef 0;
    _vehicle setAmmoCargo 0;
    _vehicle removeMagazinesTurret ["120Rnd_CMFlare_Chaff_Magazine",[0]];
};

clearWeaponCargoGlobal _vehicle;
clearMagazineCargoGlobal _vehicle;
clearItemCargoGlobal _vehicle;
clearBackpackCargoGlobal _vehicle;