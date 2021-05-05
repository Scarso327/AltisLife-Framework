/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_mapMarkers";

private _map = _this select 0;
if (isNull _map || { !([] call ULP_fnc_hasComms) }) exitWith {};

private _included = [];
private _objects = units (group player);

switch ([player] call ULP_fnc_getFaction) do {
	case "Medic": {
		_objects append (allPlayers select {
			isDowned(_x) && { !(_x in _objects) }
		});
	};
	case "Hato": {
		// TODO : HATO Inactive Vehicles...
	};
};

{
	if (isPlayer _x) then {
		if ([_x] call ULP_fnc_hasComms || { isDowned(_x) && ([player, ["Medic"]] call ULP_fnc_isFaction) }) then {
			if (isNull (objectParent _x)) then {
				_map drawIcon [
					["\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa", "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa"] select (isDowned(_x)), 
					[_x] call ULP_fnc_getTagColour, 
					getPosVisual _x, 26, 26, getDirVisual _x, 
					[_x] call ULP_fnc_getName, 
					1, 0.06, 'RobotoCondensed', 'right'
				];
			} else {
				private _vehicle = vehicle _x;
				if !(_vehicle in _included) then {
					_included pushBack _vehicle;

					private _cCount = count (crew _vehicle);
					private _unit = (crew _vehicle) param [0, objNull];
					_map drawIcon [
						getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "icon"), 
						[_unit, true] call ULP_fnc_getTagColour,
						getPosVisual _vehicle, 26, 26, getDirVisual _vehicle, 
						format ["%1%2", [_unit] call ULP_fnc_getName, ["", format [" +%1", _cCount - 1]] select (_cCount > 1)], 
						1, 0.06, 'RobotoCondensed', 'right'
					];
				};
			};
		};
	} else {
		// TODO : HATO Inactive Vehicles...
	};
} forEach _objects;