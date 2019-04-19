/*
	@File: fn_setupVehicle.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: addAction for physical shops...

	@Usage Examples:
		- [this, ["Civ", "Vehicle Store"], ["car_dealership",civilian,["civ_car_1","civ_car_2"],"civ","Oliver's Fine Cars"], "playerSide isEqualTo civilian"] call FF_fnc_setupShop;
		- [this, ["Civ", "Vehicle Store"], ["car_dealership",civilian,"civ_car_1","civ","Oliver's Fine Cars"], "playerSide isEqualTo civilian"] call FF_fnc_setupShop;
		- [this, ["Police", "Vehicle Store"], ["tpc_general_dealership",west,"cop_car_1","cop","Police Vehicle Garage"], "playerSide isEqualTo west"] call FF_fnc_setupShop;
*/
#include "..\..\script_macros.hpp"
params [
	["_object", objNull, [objNull]],
	["_title", [], [[]]],
	["_shop", [], [[]]],
	["_conditions", "", [""]]
];

if (isNull _object || {_shop isEqualTo []} || {(count _shop) != 5} || {(count _title) != 2}) exitWith {
	diag_log format["[Vehicle Setup] Failed %1 %2", _shop, _title];
};

_object enableSimulation false;
_object allowDamage false;

private _colour = switch true do {
	case (_title select 0 isEqualTo "TPC"): {"#9fc5e8"};
	case (_title select 0 isEqualTo "CIV"): {"#b4a7d6"};
	case (_title select 0 isEqualTo "TAS"): {"#b6d7a8"};
	default {"#ffe599"};
};

_object addAction[
	format[
		"<t color='%3'>[%2]</t> %1", 
		_title select 1, 
		_title select 0,
		_colour
	], LIFE(vehicleShopMenu), _shop, 1.5, true, true, "", _conditions,
	5
];