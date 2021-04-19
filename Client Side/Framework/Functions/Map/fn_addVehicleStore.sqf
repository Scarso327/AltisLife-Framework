/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "<t color='#073763'>[APC]</t> Vehicle Store", "PoliceCar", ["marker_pos_1"]] call ULP_fnc_addVehicleStore;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addVehicleStore";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "", [""]],
	["_store", "", [""]],
	["_pos", [], [[]]],
	["_condition", "", [""]]
];

private _cfgCondition = missionConfigFile >> "CfgVehicleStores" >> _store;
if (isNull _trader || { _title isEqualTo "" } || { !(isClass _cfgCondition) }) exitWith {};
_cfgCondition = getText(_cfgCondition >> "conditions");

if !(_condition isEqualTo "") then {
	_cfgCondition = _condition;
};

_trader addAction [format["%1", _title], { (_this select 3) call ULP_fnc_vehicleStore }, [_store, _pos], 1.5, true, true, "", _cfgCondition, 3];