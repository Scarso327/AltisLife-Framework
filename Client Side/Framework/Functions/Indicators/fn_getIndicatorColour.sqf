/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getIndicatorColour";

_this params [
	["_unit", objNull, [objNull]]
];

private _cfg = missionConfigFile >> "CfgIndicators" >> ([_unit] call ULP_fnc_getFaction) >> (uniform _unit);
if (isClass _cfg && { [["EnableFactionColouring", "Indicators"] call ULP_fnc_getOption] call ULP_fnc_bool }) exitWith { getArray (_cfg >> "colour") };

([
	getArray (missionConfigFile >> "CfgIndicators" >> "alignedColour"), 
	getArray (missionConfigFile >> "CfgIndicators" >> "groupColour")
] select (_unit in (units (group player))))