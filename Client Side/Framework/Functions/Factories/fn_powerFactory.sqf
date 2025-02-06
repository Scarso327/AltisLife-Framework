/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_powerFactory";

_this params [
	["_powerStation", objNull, [objNull]]
];

private _stationCfg = missionConfigFile >> "CfgPowerStations" >> worldName >> (_powerStation getVariable ["powerStation", ""]);

if (isNull _powerStation || { !isClass _stationCfg }) exitWith { false };

if !(call compile getText (_stationCfg >> "condition")) exitWith {
	["You must capture the power station to redirect it's power..."] call ULP_fnc_hint;
	false
};

private _factories = ((allMissionObjects "Land_InfoStand_V1_F") select { !isNil { _x getVariable "factory" } }) apply {
	private _cfg = missionConfigFile >> "CfgFactories" >> worldName >> (_x getVariable ["factory", ""]);

	["", getText (_cfg >> "displayName"), _x call BIS_fnc_netId, 0]
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), _factories, ["Power", "Cancel"], [_powerStation, _stationCfg], {
	_this params [
		["_powerStation", objNull, [objNull]],
		["_stationCfg", configNull, [configNull]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _factory = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> (_factory getVariable ["factory", ""]);

	if (isNull _factory || { !isClass _factoryCfg }) exitWith { ["You didn't select a factory to power!"] call ULP_fnc_hint; };

	if ((_powerStation getVariable ["powering", ""]) isEqualTo _factory) exitWith {
		["This power station is already powering that factory..."] call ULP_fnc_hint;
	};

	private _stationName = getText (_stationCfg >> "displayName");
	private _factoryName = getText (_factoryCfg >> "displayName");

	([format ["Redirecting %1 to %2", _stationName, _factoryName], 30, 
		[_powerStation, _factory, _stationCfg, _factoryName, getNumber (_stationCfg >> "tier")], 
		{ (player distance (_this select 0)) <= 5 }, {
		_this params [
			["_powerStation", objNull, [objNull]],
			["_factory", objNull, [objNull]],
			["_stationCfg", configNull, [configNull]],
			["_factoryName", "", [""]],
			["_powerTier", 0, [0]]
		];

		private _currentTarget = _powerStation getVariable ["powering", objNull];

		if !(isNull _currentTarget) then {
			[_currentTarget, -_powerTier] call ULP_fnc_setFactoryPower;
		};

		_powerStation setVariable ["powering", _factory, true];

		[_factory, _powerTier] call ULP_fnc_setFactoryPower;

		[format ["You have successfully redirect <t color='#B92DE0'>%1</t> to power <t color='#B92DE0'>%2</t>",  getText (_stationCfg >> "displayName"), _factoryName]] call ULP_fnc_hint;

		["PowerRedirected", [_location, player, _factoryName], true] call ULP_fnc_invokeEvent;
	}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress)
}, false] call ULP_fnc_selectObject;