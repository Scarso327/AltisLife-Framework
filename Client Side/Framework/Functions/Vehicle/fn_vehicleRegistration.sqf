/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleRegistration";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, false];

if (_owner isEqualType false) exitWith {
	deleteVehicle _vehicle;
	hint "Vehicle was cleaned up as it was likely spawned in.";
};

hint parseText format ["<t color='#FF0000'><t size='1.7'>Vehicle Registration</t></t><br/><t color='#FFD700'><t size='1.5'>Owner</t></t><br/> %1", _owner];