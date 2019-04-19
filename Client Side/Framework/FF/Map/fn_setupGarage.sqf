/*
	@File: fn_setupGarage.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: addAction for garages...
*/
#include "..\..\script_macros.hpp"
params [
	["_object", objNull, [objNull]],
	["_title", [], [[]]],
	["_type", "", [""]],
	["_spawmpoint", "", [""]],
	["_conditions", "", [""]]
];

if (isNull _object || {_type isEqualTo ""} || {_spawmpoint isEqualTo ""} || {(count _title) != 2}) exitWith {
	diag_log format["[Garage Setup] Failed %1 %2 %3", _type, _title, _spawmpoint];
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
		"<t color='#9000ff'>[%2]</t> %1", 
		_title select 1, 
		_title select 0,
		_colour
	],
	{
		if (life_HC_isActive) then {
			[getPlayerUID player,playerSide,_type,player] remoteExecCall ["HC_fnc_getVehicles",HC_Life]; 
		} else {
			[getPlayerUID player,playerSide,_type,player] remoteExecCall ["TON_fnc_getVehicles",2];
		};

		createDialog "Life_impound_menu";

		disableSerialization;
		ctrlSetText[2802,"Fetching Vehicles...."];

		life_garage_sp = _spawmpoint;
		life_garage_type = _type;
	}, "", 1.5, true, true, "", _conditions,
	5
];