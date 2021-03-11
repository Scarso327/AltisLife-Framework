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

clearWeaponCargoGlobal _vehicle;
clearMagazineCargoGlobal _vehicle;
clearItemCargoGlobal _vehicle;
clearBackpackCargoGlobal _vehicle;

private _texture = _vehicle getVariable ["texture", ""];
private _vehicleCfg = missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle);

if !(isClass _vehicleCfg) exitWith {};

private _turrets = _vehicleCfg >> "turrets";
if (!(_texture isEqualTo "") && { isArray (_vehicleCfg >> "Textures" >> _texture >> "turrets") }) then {
	_turrets = _vehicleCfg >> "Textures" >> _texture >> "turrets";
};

if (isArray _turrets) then {
	getArray (_turrets) params [
		["_weapons", [], [[]]],
		["_magazines", [], [[]]]
	];

	{ _vehicle removeWeapon _x; } forEach _weapons;
	{ _vehicle removeMagazinesTurret [_x select 0, _x select 1]; } forEach _magazines;
};