/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openVStore";

_this params [
	["_store", "", [""]]
];

if (dialog) exitWith {};

private _cfg = missionConfigFile >> "CfgStores" >> "CfgVirtualStores" >> _store;
if !(isClass (_cfg)) exitWith {};

if !(call compile getText(_cfg >> "conditions") || { [player, getArray(_cfg >> "factions")] call ULP_fnc_isFaction }) exitWith {
	hint "You don't have access to this store...";
};

if (createDialog "DialogVirtualStore") then {
	private _display = findDisplay 3300;
	if (isNull _display) exitWith {};

	_display setVariable ["curStore", _cfg];

	private _title = _display displayCtrl 3301;
	_title ctrlSetText getText (_cfg >> "storeName");

	private _filter = _display displayCtrl 3302;
	private _list = _display displayCtrl 3303;

	[_filter, _list] call BIS_fnc_initListNBoxSorting;
	[_display] call ULP_fnc_updateVStore;
};