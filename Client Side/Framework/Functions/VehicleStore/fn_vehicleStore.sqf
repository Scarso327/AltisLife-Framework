/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleStore";

_this params [
	["_store", "", [""]],
	["_spawns", [], [[]]]
];

if (dialog) exitWith {};

private _cfg = missionConfigFile >> "CfgVehicleStores" >> _store;
if !(isClass (_cfg)) exitWith {};

if !(call compile getText(_cfg >> "conditions")) exitWith {
	hint "You don't have access to this store...";
};

private _licenses = getArray (_cfg >> "licenses");
{
	if !([_x] call ULP_fnc_hasLicense) exitWith {
		hint format["You need these licenses to access this store: %1...", _licenses];
		breakOut "fn_vehicleStore";
	};

	nil
} count _licenses;

if (createDialog "DialogVehicleStore") then {
	private _display = findDisplay 3400;
	if (isNull _display) exitWith {};

	_display setVariable ["store", _cfg];
	_display setVariable ["spawns", _spawns];

	private _title = _display displayCtrl 3401;
	_title ctrlSetText getText (_cfg >> "storeName");
	
	private _list = _display displayCtrl 3402;
	lbClear _list;

	private _vehicleCfg = configNull;
	private _index = -1;

	{
		_vehicleCfg = [configName _x] call ULP_fnc_vehicleCfg;

		if ((count _vehicleCfg) > 0 && { call compile getText((_vehicleCfg select 1) >> "conditions") }) then {
			_vehicleCfg params [
				"", "_missionCfg", "_picture", "_name"
			];

			_index = _list lbAdd _name;
			_list lbSetPicture[_index, _picture];
			_list lbSetValue[_index, ([getNumber (_missionCfg >> "buyPrice"), getNumber (_x >> "buyPrice")] select (isNumber (_x >> "buyPrice")))];
			_list lbSetData[_index, configName _x];
		};
	} forEach ("isClass _x" configClasses (_cfg >> "Vehicles"));

	lbSort _list;
	_list lbSetCurSel 0;
};