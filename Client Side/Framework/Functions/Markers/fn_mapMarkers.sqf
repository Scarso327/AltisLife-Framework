/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_mapMarkers";

private _map = _this select 0;
if (isNull _map || { !([] call ULP_fnc_hasComms) }) exitWith {};

private _included = [];
private _objects = [] call ULP_fnc_groupUnits;

switch ([player] call ULP_fnc_getFaction) do {
	case "Medic": {
		_objects append (allPlayers select {
			isDowned(_x) && { !(_x in _objects) }
		});
	};
	case "Hato": {
		_objects append ((entities "Car") select {
			(crew _x) isEqualTo [] && { (_x getVariable ["engineLastOffTime", 0]) + (10 * 60) <= serverTime }
		});
	};
};

_objects append (ULP_Keys select {
	[_x, "TrackingDeviceUpgrade"] call ULP_fnc_hasVehicleUpgrade 
		&& { !(_x in _objects) }
		&& { (_objects arrayIntersect (crew _x)) isEqualTo [] }
});

private _isMedic = [player, ["Medic"]] call ULP_fnc_isFaction;

{
	if (_x in _included) exitWith {};

	private _isMedicAndTargetIncap = (isDowned(_x) && { _isMedic });

	if (_x isKindOf "Man") then {
		if ([_x] call ULP_fnc_hasComms || { _isMedicAndTargetIncap }) then {
			if (isNull (objectParent _x)) then {
				_map drawIcon [
					["\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa", "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\heal_ca.paa"] select (isDowned(_x)), 
					[_x] call ULP_fnc_getTagColour, 
					getPosVisual _x, 26, 26, getDirVisual _x, 
					[_x] call ULP_fnc_getName, 
					1, 0.06, 'RobotoCondensed', 'right'
				];

				if (_isMedicAndTargetIncap) then {
					_map drawIcon [
						"\a3\Data_f\clear_empty.paa", 
						[_x] call ULP_fnc_getTagColour, 
						getPosVisual _x, 26, 26, getDirVisual _x,  
						[(_x getVariable ["IncapacitatedBleedOutTime", serverTime + 10]) - serverTime, "MM:SS"] call BIS_fnc_secondsToString, 
						1, 0.06, 'RobotoCondensed', 'left'
					];
				};
			} else {
				private _vehicle = vehicle _x;
				private _crew = crew _vehicle;

				private _cCount = count _crew;
				private _unit = _crew param [0, objNull];

				_map drawIcon [
					getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "icon"), 
					[_unit, true] call ULP_fnc_getTagColour,
					getPosVisual _vehicle, 26, 26, getDirVisual _vehicle, 
					format ["%1%2", [_unit] call ULP_fnc_getName, ["", format [" +%1", _cCount - 1]] select (_cCount > 1)], 
					1, 0.06, 'RobotoCondensed', 'right'
				];
			};
		};
	} else {
		_map drawIcon [
			getText (configFile >> "CfgVehicles" >> (typeOf _x) >> "icon"), 
			[[0.50, 0.50, 0.50, 1.00], [0, 0.901, 0.074, 1]] select (_x in ULP_Keys),
			getPosVisual _x, 26, 26, getDirVisual _x, "", 1
		];
	};

	nil
} count _objects;