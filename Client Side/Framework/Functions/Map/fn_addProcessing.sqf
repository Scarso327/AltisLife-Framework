/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "<t color='#073763'>[APC]</t> License Store", "DVLA"] call ULP_fnc_addProcessing;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addProcessing";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "", [""]],
	["_store", "", [""]]
];

private _cfgCondition = missionConfigFile >> "CfgProcessingStores" >> _store;
if (isNull _trader || { _title isEqualTo "" } || { !(isClass _cfgCondition) }) exitWith {};
_cfgCondition = getText(_cfgCondition >> "condition");

_trader addAction [format["%1", _title], { (_this select 3) call ULP_fnc_openProcessing }, _store, 1.75, true, true, "", _cfgCondition, 3];