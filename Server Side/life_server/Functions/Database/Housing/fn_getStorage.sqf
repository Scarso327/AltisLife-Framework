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

// Stupid but works to limit ability for people to open two "fresh" ones at the same time
// Should probably develop a queue system?
private _randomDelay = random 3;

[_randomDelay, [_house, _box], {
	_this params [ "_house", "_box" ];

	private _container = _box getVariable ["container", objNull];

	if !(isNull _container) exitWith {
		["HouseStorage", [_house, _container]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
	};

	private _containerType = typeOf _box;
	private _containerCfg = missionConfigFile >> "CfgVehicles" >> _containerType;

	if (isText (_containerCfg >> "supply")) then {
		_containerType = getText (_containerCfg >> "supply");
	};

	private _container = createVehicle [_containerType, getPosATL _box, [], 0, "CAN_COLLIDE"];
	_container allowDamage false;
	_container hideObjectGlobal true;

	_box setVariable ["container", _container];
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
}] call ULP_fnc_waitExecute;