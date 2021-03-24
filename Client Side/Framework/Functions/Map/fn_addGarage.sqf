/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, ["Car"], ["marker_pos_1"]] call ULP_fnc_addGarage;
** 	[this, ["Car"], ["marker_pos_1"], true, true, true] call ULP_fnc_addGarage; // Impound
** 	[this, ["Car"], ["marker_pos_1"], false, true, false, "[player] call ULP_fnc_getFaction isEqualTo ""Police""", "<t color='#3266A8'>[APC]</t>"] call ULP_fnc_addGarage;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addGarage";

_this params [
	["_trader", objNull, [objNull]],
	["_types", ["Car", "Air", "Ship"], [[]]],
	["_pos", [], [[]]],
	["_includeGarage", true, [false]],
	["_includeStore", true, [false]],
	["_impound", false, [true]],
	["_condition", "true", [""]],
	["_title", "<t color='#B92DE0'>[CIV]</t>", [""]]
];

if (isNull _trader || { _title isEqualTo "" } || { _condition isEqualTo "" }) exitWith {};

if (_includeGarage) then {
	_trader addAction [format["%1 %2 %3", _title, 
	([
		"Vehicle",
		_types select 0
	] select ((count _types) isEqualTo 1)), ([
		"Garage",
		"Impound"
	] select (_impound))], { (_this select 3) call ULP_fnc_openGarage }, [_types, _pos, _impound], 1.5, true, true, "", _condition, 3];
};
if (_includeStore) then {
	_trader addAction [format["%1 Store Vehicle", _title], { [(_this select 0), (_this select 3)] call ULP_fnc_storeVehicle }, _types, 1, true, true, "", _condition, 3];
};