/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "<t color='#073763'>[APC]</t> Market", "Police"] call ULP_fnc_addMarket;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addMarket";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "", [""]],
	["_store", "", [""]]
];

private _cfgCondition = missionConfigFile >> "CfgStores" >> "CfgVirtualStores" >> _store;
if (isNull _trader || { _title isEqualTo "" } || { !(isClass _cfgCondition) }) exitWith {};
_cfgCondition = getText(_cfgCondition >> "conditions");

_trader addAction [format["%1", _title], { [(_this select 3)] call ULP_fnc_openVStore }, _store, 1.5, true, true, "", _cfgCondition, 3];