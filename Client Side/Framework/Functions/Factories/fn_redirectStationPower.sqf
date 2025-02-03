/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_redirectStationPower";

_this params [
	["_location", objNull, [objNull]],
	["_powerStation", "", [""]],
	["_factory", "", [""]]
];

private _stationCfg = missionConfigFile >> "CfgPowerStations" >> worldName >> _powerStation;
private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> _factory;
if (isNull _location || { !isClass _stationCfg } || { !isClass _factoryCfg }) exitWith { false };

if !(call compile getText (_stationCfg >> "condition")) exitWith {
	["You must capture the power station to redirect it's power..."] call ULP_fnc_hint;
	false
};

if ((_location getVariable ["powering", ""]) isEqualTo _factory) exitWith {
	["This power station is already powering that factory..."] call ULP_fnc_hint;
	false
};

([format ["Redirecting %1 to %2", getText(_stationCfg >> "displayName"), getText(_factoryCfg >> "displayName")], 30, 
	[_location, _stationCfg, _factoryCfg], 
	{ (player distance (_this select 0)) <= 5 }, {
	_this params [ "_location", "_stationCfg", "_factoryCfg" ];

	private _factory = configName _factoryCfg;
	diag_log format["ULP_SRV_Factory_%1_Power", _factory];

	_location setVariable ["powering", _factory, true];
	missionNamespace setVariable [format["ULP_SRV_Factory_%1_Power", _factory], getNumber (_stationCfg >> "tier"), true];

	[format ["You have successfully redirect <t color='#B92DE0'>%1</t> to power <t color='#B92DE0'>%2</t>", getText (_stationCfg >> "displayName"), getText(_factoryCfg >> "displayName")]] call ULP_fnc_hint;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress)