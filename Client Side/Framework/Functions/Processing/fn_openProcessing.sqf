/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openProcessing";

_this params [
	["_store", "", [""]]
];

private _cfg = missionConfigFile >> "CfgProcessingStores" >> _store;
if (dialog || { !(isClass _cfg) }) exitWith {};

if !(call compile getText(_cfg >> "condition")) exitWith {
	["You don't have access to this site!"] call ULP_fnc_hint;
};

if (createDialog "DialogProcessing") then {
	private _display = findDisplay 4000;
	if (isNull _display) exitWith {};

	_display setVariable ["store", _cfg];

	private _title = _display displayCtrl 4001;
	_title ctrlSetText getText (_cfg >> "title");

	[] call ULP_fnc_listProcesses;
};