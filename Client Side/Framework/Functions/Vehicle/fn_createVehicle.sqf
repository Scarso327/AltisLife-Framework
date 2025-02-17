/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_createVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_createVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_class", "", [""]],
	["_point", [[0, 0, 0], 0], [[]]],
	["_texture", "", [""]],
	["_id", -1, [0]],
	["_upgrades", createHashMap, [createHashMap]],
	["_owner", [getPlayerUID player, [profileName, [player] call ULP_fnc_getFaction]], [[]]],
	["_hint", hasInterface, [true]]
];

_point params [
	"_pos", "_dir"
];

private _vehicle = createVehicle [_class, _pos, [], 0, "CAN_COLLIDE"];
_vehicle allowDammage false;
_vehicle setDir _dir;
_vehicle lock 2;

if (_id >= 0) then {
	_vehicle setVariable ["vehicle_id", _id, true];
};

if (_owner isEqualType ["", "", ""]) then {
	_vehicle setVariable ["vehicle_owners", createHashMapFromArray [_owner], true];
};

if !(_upgrades isEqualTo createHashMap) then {
	_vehicle setVariable ["object_upgrades", _upgrades, true];
};

[_vehicle, _texture] call ULP_fnc_skinVehicle;
[_vehicle] call ULP_fnc_initVehicle;

_vehicle allowDammage true;
_vehicle addItemCargoGlobal ["ToolKit", 1];
ULP_Keys pushBackUnique _vehicle;

if (_hint) then {
	["Your vehicle is now ready..."] call ULP_fnc_hint;
};