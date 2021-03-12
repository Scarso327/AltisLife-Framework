/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_destroyGarage";

_this params [
	["_vehicleId", -1, [0]]
];

if (_vehicleId isEqualTo -1) exitWith {};

[format["UPDATE vehicles SET sold='1' WHERE id='%1'", [_vehicleId, ""] call ULP_fnc_numberText ], 1] call DB_fnc_asyncCall;