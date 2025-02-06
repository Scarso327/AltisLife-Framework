/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_salvageVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_salvageVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_factory", objNull, [objNull]]
];

private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> (_factory getVariable ["factory", ""]);
if !(isClass _factoryCfg) exitWith {};

if (_factory getVariable ["locked", false]) exitWith {
	["DialogSalvageFactory", _this] call ULP_UI_fnc_createDialog;
};

private _near = ((_factory nearEntities [["Car", "Air", "Ship"], 15]) select {
	!([_x] call ULP_fnc_getVehicleOwner isEqualTo "")
});

if (_near isEqualTo []) exitWith {
	["There are no vehicles nearby that can be salvaged!"] call ULP_fnc_hint;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
 ([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
 [_picture, _name, _x call BIS_fnc_netId, 0];
}), ["Salvage", "Cancel"], [_factory, _factoryCfg], {
	_this params [
		["_factory", player, [objNull]],
		["_factoryCfg", configNull, [configNull]],
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["You didn't select a vehicle to salvage!"] call ULP_fnc_hint; };

	private _vehicleTypeOf = typeOf _vehicle;

	private _cfg = [_vehicleTypeOf] call ULP_fnc_vehicleCfg;
	if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

	_cfg params [
		"", "_missionCfg", "_picture", "_name"
	];

	if !(isClass _missionCfg) exitWith {};

	private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> (_factory getVariable ["factory", ""]);
	if !(isClass _factoryCfg) exitWith {};

	if !(isClass (_factoryCfg >> "Products" >> _vehicleTypeOf)) exitWith { ["This vehicle can't be salvaged"] call ULP_fnc_hint; };

	player setVariable ["salvageFactory", _factory];

	["FactoryStarted", { 
		[_this param [0, ""]] call ULP_fnc_hint; 

		private _factory = player getVariable ["salvageFactory", objNull];

		if (!isNull _factory && { _factory getVariable ["locked", false] }) then {
			["DialogSalvageFactory", [_factory]] call ULP_UI_fnc_createDialog;
			player setVariable ["salvageFactory", nil];
		};
	}, true] call ULP_fnc_addEventHandler; 
	
	[_factory, player, _vehicleTypeOf, [_vehicle]] remoteExecCall ["ULP_SRV_fnc_startFactory", RSERV];
}, false] call ULP_fnc_selectObject;