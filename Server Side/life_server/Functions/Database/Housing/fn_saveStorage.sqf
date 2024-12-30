/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_saveStorage";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_saveStorage, _this] call ULP_fnc_directCall;
};

_this params [
	["_container", objNull, [objNull]]
];

private _box = _container getVariable ["storage_box", objNull];
private _id = _box getVariable ["building_id", -1];

if (isNull _container || { isNull _box } || { _id isEqualTo -1 }) exitWith { false };

private _storage = [getItemCargo _container, getMagazineCargo _container, getWeaponCargo _container, getBackpackCargo _container];

{
	private _temp = [];

	_x params [ "_items", "_amounts" ];
	
	{
		_temp pushBack [_x, _amounts param [_forEachIndex, 0]];
	} forEach _items;

	_storage set [_forEachIndex, _temp];
} forEach _storage;

_box setVariable ["ULP_PhysicalCargo", _storage];

[
	format [
		"UPDATE `houses` SET `storage`='%1' WHERE `id`='%2'",
		[_storage] call DB_fnc_mresArray, [_id, ""] call ULP_fnc_numberText
	], 1
] call DB_fnc_asyncCall;

deleteVehicle _container;
true