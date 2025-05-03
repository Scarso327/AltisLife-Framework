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
	["You don't have access to this store!"] call ULP_fnc_hint;
};

if (createDialog "DialogVirtualStore") then {
	private _display = findDisplay 3300;
	if (isNull _display) exitWith {};

	private _allowPayByBank = [getNumber (_cfg >> "allowPayByBank")] call ULP_fnc_bool;

	_display setVariable ["curStore", _cfg];
	_display setVariable ["allowPayByBank", _allowPayByBank];

	private _title = _display displayCtrl 3301;
	_title ctrlSetText getText (_cfg >> "storeName");

	if !(_allowPayByBank) then {
		private _checkbox = _display displayCtrl 3307;
		private _paymentText = _display displayCtrl 3308;

		_checkbox cbSetChecked false;
		_checkbox ctrlEnable false;
		_checkbox ctrlSetTooltip "This store doesn't support bank payments";

		_paymentText ctrlEnable false;
	};

	private _filter = _display displayCtrl 3302;
	private _list = _display displayCtrl 3303;

	[_filter, _list] call BIS_fnc_initListNBoxSorting;
	[_display] call ULP_fnc_updateVStore;
};