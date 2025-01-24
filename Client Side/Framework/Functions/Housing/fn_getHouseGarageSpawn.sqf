/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getHouseGarageSpawn";

_this params [
	["_building", objNull, [objNull]]
];

(getArray (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _building) >> "Garage" >> "spawnPos")) params [ "_pos", "_dir" ];

[(_building modelToWorldVisual _pos), (getDir _building) + _dir]