/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openGarage";

_this params [
	["_types", ["Car", "Air", "Ship"], [[]]],
	["_spawns", [], [[]]],
	["_impound", false, [true]]
];

private _faction = [player] call ULP_fnc_getFaction;
if (dialog || { !([_faction, "vehicles"] call ULP_fnc_factionPresistant) }) exitWith {};

if (createDialog "DialogGarage") then {
	private _display = findDisplay 3500;
	if (isNull _display) exitWith {};

	(_display displayCtrl 3506) ctrlShow !_impound;
	(_display displayCtrl 3507) ctrlShow !_impound;
	(_display displayCtrl 3505) ctrlSetStructuredText parseText ([
		"<t align = 'center'>Retrieve</t>", "<t align = 'center'>Unimpound</t>"
	] select (_impound));

	_display setVariable ["impound", _impound];
	_display setVariable ["spawns", _spawns];
	_display setVariable ["GarageRetrievedEvent", ["GarageRetrieved", { _this call ULP_fnc_populateGarage; }, true] call ULP_fnc_addEventHandler];

	[getPlayerUID player, _faction, _types, _impound] remoteExecCall ["ULP_SRV_fnc_getGarage", RSERV];
};