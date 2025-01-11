/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setupHouse";

_this params [
	["_house", objNull, [objNull]],
	["_params", [], [[]]]
];

_params params [
	"_id", "_owner", ["_shared", false, [true]], ["_name", "", [""]], ["_pStorage", [], [[]]], ["_vStorage", [], [[]]]
];

_house allowDamage false;

_house setVariable ["building_id", _id, true];
_house setVariable ["building_owner", _owner, true];
_house setVariable ["building_shared", _shared, true];

if !(_name isEqualTo "") then {
	_house setVariable ["building_name", _name, true];
};

// Lock Doors...
for "_i" from 1 to (getNumber(configFile >> "CfgVehicles" >> (typeOf _house) >> "numberOfDoors")) do {
	_house setVariable [format ["bis_disabled_Door_%1", _i], 1, true];
};

private _cfg = missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house);
if (isClass (_cfg >> "Storage")) then {
	getArray (_cfg >> "Storage" >> "position") params [
		"_pos", ["_dir", 0, [0]]
	];

	private _storage = createSimpleObject [getText (_cfg >> "Storage" >> "object"), getPos _house];
	_storage setPosASL AGLtoASL (_house modelToWorldVisual _pos);
	_storage setDir (getDir _house) - _dir;

	_house setVariable ["building_storage", _storage];
	_storage setVariable ["building", _house, true];
	_storage setVariable ["building_id", _id];
	_storage setVariable ["ULP_PhysicalCargo", _pStorage];
	_storage setVariable ["ULP_VirtualCargo", createHashMapFromArray _vStorage, true];
	_storage setVariable ["LastStorage", []];
};

ULP_SRV_Houses pushBackUnique _house;