/*
	@File: fn_setupShop.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: addAction for physical shops...

	@Usage Examples:
		- [this, ["Civ", "General Store"], "general_store", ""] call FF_fnc_setupShop;
		- [this, ["Civ", "Go-Kart Store"], "go_karting_store", "playerSide isEqualTo civilian && license_civ_go_karting"] call FF_fnc_setupShop;
		- [this, ["Police", "Equipment Locker"], "tpc_general_Store", "playerSide isEqualTo west"] call FF_fnc_setupShop;
		- [this, ["TAS", "General Equipment"], "nhs_general_store", "playerSide isEqualTo independent"] call FF_fnc_setupShop;
*/
#include "..\..\script_macros.hpp"
params [
	["_object", objNull, [objNull]],
	["_title", [], [[]]],
	["_shop", "", [""]],
	["_conditions", "", [""]]
];

if (isNull _object || {_shop isEqualTo ""} || {(count _title) != 2}) exitWith {
	diag_log format["[Shop Setup] Failed %1 %2", _shop, _title];
};

_object enableSimulation false;
_object allowDamage false;

private _colour = switch true do {
	case (_title select 0 isEqualTo "TPC"): {"#9fc5e8"};
	case (_title select 0 isEqualTo "CIV"): {"#b4a7d6"};
	case (_title select 0 isEqualTo "TAS"): {"#b6d7a8"};
	case (_title select 0 isEqualTo "IDAP"): {"#ff9900"};
	default {"#ffe599"};
};

_object addAction[
	format[
		"<t color='%3'>[%2]</t> %1", 
		_title select 1, 
		_title select 0,
		_colour
	], LIFE(weaponShopMenu), _shop, 1.5, true, true, "", _conditions,
	5
];