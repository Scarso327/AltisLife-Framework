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

private _cfg = missionConfigFile >> "CfgVehicleStores" >> _store;
if (isNull _trader || { _title isEqualTo "" } || { !(isClass _cfg) }) exitWith {};

if (_condition isEqualTo "") then {
	_condition = getText(_cfg >> "conditions");
};

_trader addAction [format["%1", _title], { (_this select 3) call ULP_fnc_vehicleStore }, [_store, _pos], 1.5, true, true, "", _condition, 3];

[_trader, getText(_cfg >> "storeName")] call ULP_fnc_setTraderName;