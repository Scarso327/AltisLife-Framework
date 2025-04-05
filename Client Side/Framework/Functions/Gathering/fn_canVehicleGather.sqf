/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canVehicleGather";

_this params [
	["_vehicle", objNull, [objNull]]
];

(!isNull _vehicle 
	&& { (typeOf _vehicle) isEqualTo "O_Truck_03_device_F" } 
	&& { isNull (driver _vehicle) }
	&& { (speed _vehicle) isEqualTo 0 }
	&& { (fuel _vehicle) > 0.1 })