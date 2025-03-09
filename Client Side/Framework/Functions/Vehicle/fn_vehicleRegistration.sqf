/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleRegistration";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _owner = _this call ULP_fnc_getVehicleOwnerName;

if (_owner isEqualTo "Unknown") exitWith {
	deleteVehicle _vehicle;
	["Vehicle was cleaned up as it was likely spawned in..."] call ULP_fnc_hint;
};

[format ["<t color='#FF0000'><t size='1.7'>Vehicle Registration</t></t><br/><t color='#FFD700'><t size='1.5'>Owner</t></t><br/> %1", _owner]] call ULP_fnc_hint;