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

		{ _vehicle removeMagazinesTurret [_x, _turretPath]; } forEach _magazines;
		{ _vehicle removeWeaponTurret [_x, _turretPath]; } forEach _weapons;

	} forEach (getArray _turrets);
};