/*
	@File: fn_setupShop.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: addAction for physical shops...

	@Usage Examples:
		- [this, ["Civ", "General Store"], "general_store", ""] call FF_fnc_setupShop;
		- [this, ["Civ", "Go-Kart Store"], "go_karting_store", "playerSide isEqualTo civilian && license_civ_go_karting"] call FF_fnc_setupShop;
		- [this, ["Police", "Equipment Locker"], "tpc_general_Store", "playerSide isEqualTo west"] call FF_fnc_setupShop;
		- [this, ["NHS", "General Equipment"], "nhs_general_store", "playerSide isEqualTo independent"] call FF_fnc_setupShop;
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

_object addAction[
	format[
		"<t color='#9000ff'>[%2]</t> %1", 
		_title select 1, 
		_title select 0
	], LIFE(weaponShopMenu), _shop, 1.5, true, true, "", _conditions,
	5
];