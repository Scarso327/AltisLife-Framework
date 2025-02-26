/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_postInitTerritories";

["Post-Initialising Territories..."] call ULP_fnc_logIt;

private _territories = [];

{
	private _cfg = _x;

	private _flag = createVehicle ["Flag_Syndikat_F", getArray (_cfg >> "flagPos"), [], 0, "CAN_COLLIDE"];
	_flag allowDamage false;
	_flag enableDynamicSimulation true;

	_flag setVariable ["config", configName _cfg, true];

	private _sites = [];

	{
		getArray (_x >> "pos") params [
			"_pos", ["_dir", 0, [0]]
		];

		private _container = createVehicle ["Land_Cargo10_red_F", _pos, [], 0, "CAN_COLLIDE"];
		_container setPosATL _pos;
		_container setDir _dir;

		_container allowDamage false;
		_container enableSimulation false;

		_container setVariable ["Territory", _flag, true];
		_container setVariable ["SiteCfg", _x];

		_container setVariable ["hasPlayerTags", true, true];
		_container setVariable ["name", getText (_x >> "displayName"), true];

		_sites pushBack _container;
	} forEach ("isClass _x" configClasses (_cfg >> "Sites"));

	_flag setVariable ["sites", _sites];

	_territories pushBack _flag;
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgTerritories" >> worldName));

missionNamespace setVariable ["ULP_Territories", _territories, true];

[] call ULP_SRV_fnc_territoriesTick;