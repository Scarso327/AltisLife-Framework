/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "<t color='#073763'>[APC]</t> License Store", "DVLA"] call ULP_fnc_addLicenseStore;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addLicenseStore";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "", [""]],
	["_store", "", [""]]
];

private _cfg = missionConfigFile >> "CfgLicenseStores" >> _store;
if (isNull _trader || { _title isEqualTo "" } || { !(isClass _cfg) }) exitWith {};

private _condition = getText(_cfg >> "condition");

_trader addAction [format["%1", _title], { (_this select 3) call ULP_fnc_openLicenses }, _store, 1.5, true, true, "", _condition, 3];

[_trader, getText(_cfg >> "title")] call ULP_fnc_setTraderName;