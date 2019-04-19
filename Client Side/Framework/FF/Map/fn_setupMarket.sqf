/*
	@File: fn_setupMarket.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: addAction for virtual shops...

	@Usage Examples:
		- [this, ["Civ", "Market"], "general_market", ""] call FF_fnc_setupMarket;
		- [this, ["Civ", "Mineral Exports"], "mineral_exports", "playerSide isEqualTo civilian"] call FF_fnc_setupMarket;
		- [this, ["Rebel", "Market"], "syndikat_outpost", "playerSide isEqualTo civilian && license_civ_syndikat"] call FF_fnc_setupMarket;
		- [this, ["Police", "Market"], "tpc_market", "playerSide isEqualTo west"] call FF_fnc_setupMarket;
		- [this, ["TAS", "Market"], "nhs_market", "playerSide isEqualTo independent"] call FF_fnc_setupMarket;
*/
#include "..\..\script_macros.hpp"
params [
	["_object", objNull, [objNull]],
	["_title", [], [[]]],
	["_shop", "", [""]],
	["_conditions", "", [""]]
];

if (isNull _object || {_shop isEqualTo ""} || {(count _title) != 2}) exitWith {
	diag_log format["[Market Setup] Failed %1 %2", _shop, _title];
};

_object enableSimulation false;
_object allowDamage false;

private _colour = switch true do {
	case (_title select 0 isEqualTo "TPC"): {"#9fc5e8"};
	case (_title select 0 isEqualTo "CIV"): {"#b4a7d6"};
	case (_title select 0 isEqualTo "TAS"): {"#b6d7a8"};
	default {"#9000ff"};
};

_object addAction[
	format[
		"<t color='#9000ff'>[%2]</t> %1", 
		_title select 1, 
		_title select 0,
		_colour
	], LIFE(virt_menu), _shop, 1.5, true, true, "", _conditions,
	5
];