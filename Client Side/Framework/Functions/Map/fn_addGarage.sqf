/*
** Author: Jack "Scarso" Farhall
** Description: 
** Usage:
** 	[this, ["Car"], ["marker_pos_1"]] call ULP_fnc_addGarage;
** 	[this, ["Car", "Air", "Ship"], ["marker_pos_1"], true] call ULP_fnc_addGarage; // Impound
** 	[this, ["Car"], ["marker_pos_1"], false, "[player] call ULP_fnc_getFaction isEqualTo ""Police""", "<t color='#3266A8'>[APC]</t>"] call ULP_fnc_addGarage;
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addGarage";

_this params [
	["_trader", objNull, [objNull]],
	["_types", ["Car", "Helicopter", "Plane", "Ship"], [[]]],
	["_pos", [], [[]]],
	["_impound", false, [true]],
	["_condition", "true", [""]],
	["_title", "<t color='#B92DE0'>[Civilian]</t>", [""]]
];

if (isNull _trader || { _title isEqualTo "" } || { _condition isEqualTo "" }) exitWith {};

private _name = format ["%1 %2", ([
	"Vehicle",
	_types select 0
] select ((count _types) isEqualTo 1)), ([
	"Garage",
	"Impound"
] select (_impound))];

_trader addAction [format["%1 %2", _title, _name], { (_this select 3) call ULP_fnc_openGarage }, [_types, _pos, _impound], 1.5, true, true, "", _condition, 3];

[_trader, _name] call ULP_fnc_setTraderName;