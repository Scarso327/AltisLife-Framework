/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setVehicleAmmo";

_this params [
	["_vehicle", objNull, [objNull]]
];

_vehicle setAmmoCargo 0;
_vehicle setFuelCargo 0;
_vehicle setRepairCargo 0;

[_vehicle] call ULP_fnc_clearCargo;

// Remove all turret weapons and ammo
private _turrets = (allTurrets [_vehicle, true]) + [[-1]];

{
	private _turretPath = _x;

	if !(_vehicle turretLocal _turretPath) exitWith {};

	{
		_vehicle removeMagazinesTurret [_x, _turretPath];
	} forEach (_vehicle magazinesTurret _turretPath);

	{
		_vehicle removeWeaponTurret [_x, _turretPath];
	} forEach (_vehicle weaponsTurret _turretPath);
} forEach _turrets;

private _texture = _vehicle getVariable ["texture", ""];
private _vehicleCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle);

if !(isClass _vehicleCfg) exitWith {};

private _turrets = _vehicleCfg >> "turrets";
if (!(_texture isEqualTo "") && { isArray (_vehicleCfg >> "Textures" >> _texture >> "turrets") }) then {
	_turrets = _vehicleCfg >> "Textures" >> _texture >> "turrets";
};

if (isArray _turrets) then {
	{
		_x params [ "_turretPath", "_weapons", "_magazines" ];

		if !(_vehicle turretLocal _turretPath) exitWith {};

		{ _vehicle addWeaponTurret [_x, _turretPath]; } forEach _weapons;
		{ _vehicle addMagazineTurret [_x, _turretPath]; } forEach _magazines;

	} forEach (getArray _turrets);
};

private _pylons = _vehicleCfg >> "pylons";
if (!(_texture isEqualTo "") && { isArray (_vehicleCfg >> "Textures" >> _texture >> "pylons") }) then {
	_pylons = _vehicleCfg >> "Textures" >> _texture >> "pylons";
};

if (isArray _pylons) then {
	{
		_vehicle setPylonLoadout [_forEachIndex + 1, _x, true, []];
	} forEach (getArray _pylons);
};