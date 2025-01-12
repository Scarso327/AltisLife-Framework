/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getBuildingDoors";

_this params [
	["_building", objNull, [objNull]]
];

private _doors = [];
private _doorCount = getNumber (configFile >> "CfgVehicles" >> (typeOf _building) >> "numberOfDoors");

if (_doorCount isEqualTo 0) exitWith { 0 };

for "_i" from 1 to _doorCount do {
	_doors pushBack (_building modelToWorld (_building selectionPosition format ["Door_%1_trigger", _i]));
};

_doors