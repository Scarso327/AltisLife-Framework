/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getStorage";

_this params [
	["_house", objNull, [objNull]]
];

private _box = _house getVariable ["building_storage", objNull];
if (isNull _box) exitWith {
	["HouseStorage", [_house, objNull]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

private _container = createVehicle [typeOf _box, [0,0,0], [], 0, "CAN_COLLIDE"];

_container setVariable ["storage_box", _box];

clearWeaponCargoGlobal _container;
clearItemCargoGlobal _container;
clearMagazineCargoGlobal _container;
clearBackpackCargoGlobal _container;

{
	private _type = _forEachIndex;

	{
		switch (_type) do {
			case 0: { _container addItemCargoGlobal _x };
			case 1: { _container addMagazineCargoGlobal _x };
			case 2: { _container addWeaponCargoGlobal _x };
			case 3: { _container addBackpackCargoGlobal _x };
		};
	} forEach _x;
} forEach (_box getVariable ["ULP_PhysicalCargo", []]);

["HouseStorage", [_house, _container]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];