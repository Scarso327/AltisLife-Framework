/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openGarage";

_this params [
	["_types", ["Car", "Air", "Ship"], [[]]],
	["_spawns", [], [[]]]
];

private _faction = [player] call ULP_fnc_getFaction;
if (dialog || { !([_faction, "vehicles"] call ULP_fnc_factionPresistant) }) exitWith {};

if (createDialog "DialogGarage") then {
	private _display = findDisplay 3500;
	if (isNull _display) exitWith {};

	_display setVariable ["spawns", _spawns];
	_display setVariable ["GarageRetrievedEvent", ["GarageRetrieved", { _this call ULP_fnc_populateGarage; }, true] call ULP_fnc_addEventHandler];

	[getPlayerUID player, _faction, _types] remoteExecCall ["ULP_SRV_fnc_getGarage", RSERV];
};