/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_calcMaxConversionVehicle";

_this params [
	["_vehicle", objNull, [objNull]],
	["_materials", [], []]
];

private _cargo = _vehicle getVariable ["ULP_VirtualCargo", createHashMap];
private _possibleConversions = [];

{
	_possibleConversions pushBack (floor ((_cargo getOrDefault [_x select 0, 0]) / (_x select 1)));
} forEach _materials;

selectMin _possibleConversions