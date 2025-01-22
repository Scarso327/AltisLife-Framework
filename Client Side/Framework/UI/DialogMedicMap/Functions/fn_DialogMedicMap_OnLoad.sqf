/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_OnLoad";

_this params [ "_display" ];

if (isNull _display) exitWith {};

disableSerialization;
uiNamespace setVariable ["DialogMedicMap", _display];

private _incapacitatedPlayers = allPlayers select { isDowned(_x) };

_display setVariable ["IncapacitatedPlayers", _incapacitatedPlayers];

_display setVariable ["Incapacitated", ["Incapacitated", {
	_this params [ "_unit" ];

	private _display = uiNamespace getVariable ["DialogMedicMap", displayNull];
	if (isNull _display) exitWith {};

	private _incapacitatedPlayers = _display getVariable ["IncapacitatedPlayers", []];
	if (_unit in _incapacitatedPlayers) exitWith {};

	_incapacitatedPlayers pushBackUnique _unit;

	_display setVariable ["IncapacitatedPlayers", _incapacitatedPlayers];
	[_display] call ULP_UI_fnc_DialogMedicMap_LoadList;
}] call ULP_fnc_addEventHandler];

_display setVariable ["Died", ["Died", {
	_this params [ "_unit" ];

	private _display = uiNamespace getVariable ["DialogMedicMap", displayNull];
	if (isNull _display) exitWith {};

	private _incapacitatedPlayers = _display getVariable ["IncapacitatedPlayers", []];
	
	if !(_unit in _incapacitatedPlayers) exitWith {};

	_incapacitatedPlayers deleteAt (_incapacitatedPlayers find _unit);

	_display setVariable ["IncapacitatedPlayers", _incapacitatedPlayers];
	[_display] call ULP_UI_fnc_DialogMedicMap_LoadList;
}] call ULP_fnc_addEventHandler];

_display setVariable ["AssignedMedicChanged", ["AssignedMedicChanged", {
	[_display] call ULP_UI_fnc_DialogMedicMap_LoadList;
}] call ULP_fnc_addEventHandler];

[_display] call ULP_UI_fnc_DialogMedicMap_LoadList;