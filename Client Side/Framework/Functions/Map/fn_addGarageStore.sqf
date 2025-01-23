/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, ["Car", "Air", "Ship"]] call ULP_fnc_addGarageStore;
** 	[this, ["Car"], "[player] call ULP_fnc_getFaction isEqualTo ""Police""", "<t color='#3266A8'>[APC]</t>"] call ULP_fnc_addGarageStore;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addGarageStore";

_this params [
	["_trader", objNull, [objNull]],
	["_types", ["Car", "Helicopter", "Plane", "Ship"], [[]]],
	["_condition", "true", [""]],
	["_title", "<t color='#B92DE0'>[Civilian]</t>", [""]]
];

if (isNull _trader || { _title isEqualTo "" } || { _condition isEqualTo "" }) exitWith {};

_trader addAction [format["%1 Store Vehicle", _title], { [(_this select 0), (_this select 3)] call ULP_fnc_storeVehicle }, _types, 1.5, true, true, "", _condition, 3];
