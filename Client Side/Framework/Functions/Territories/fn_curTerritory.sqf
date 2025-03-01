/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_curTerritory";

_this params [
	["_unit", player, [objNull]]
];

private _pos = getPos _unit;

private _index = ULP_Territories findIf { _pos inPolygon getArray (missionConfigFile >> "CfgTerritories" >> worldName >> (_x getVariable ["config", configNull]) >> "borderVertices") };

(ULP_Territories param [_index, objNull])