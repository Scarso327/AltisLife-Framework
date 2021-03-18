/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, "<t color='#073763'>[CIV]</t> Rob Store", "FuelStation", "Kavala "] call ULP_fnc_addRobAction;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addRobAction";

_this params [
	["_trader", objNull, [objNull]],
	["_title", "", [""]],
	["_store", "", [""]],
	["_name", "", [""]]
];

if (isNull _trader || { _title isEqualTo "" }) exitWith {};

_trader addAction [format["%1", _title], { [(_this select 0), (_this select 3) select 0, (_this select 3) select 1] call ULP_fnc_robObject }, [_store, _name], 1.5, true, true, "", "true", 3];