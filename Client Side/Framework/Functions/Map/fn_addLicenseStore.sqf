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

private _cfgCondition = missionConfigFile >> "CfgLicenseStores" >> _store;
if (isNull _trader || { _title isEqualTo "" } || { !(isClass _cfgCondition) }) exitWith {};
_cfgCondition = getText(_cfgCondition >> "conditions");

_trader addAction [format["%1", _title], { (_this select 3) call ULP_fnc_openLicenses }, _store, 1.25, true, true, "", _cfgCondition, 3];