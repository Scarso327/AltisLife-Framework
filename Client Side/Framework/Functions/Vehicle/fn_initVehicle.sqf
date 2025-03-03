/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_initVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_vehicle", objNull, [objNull]],
	["_jip", false, [true]]
];

private _cfg = missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle);
if (isNull _vehicle || { _vehicle getVariable ["ready", false] }) exitWith {};
_vehicle setVariable ["ready", true];

if (local _vehicle) then {
	if (_jip) exitWith {};

	if ([getNumber(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "isUAV")] call ULP_fnc_bool) then {
        createVehicleCrew _vehicle;
        _vehicle setSpeedMode "FULL";
        _vehicle setVehicleRadar 0;
		_vehicle setAutonomous false;
    };

	[_vehicle] call ULP_fnc_setVehicleAmmo;
	_vehicle addItemCargoGlobal ["ToolKit", 1];

	[_vehicle] remoteExecCall ["ULP_fnc_initVehicle", -clientOwner];
	_vehicle setVariable["jipReady", true, true];
};

_vehicle addEventHandler ["Engine", { _this call ULP_fnc_onVehicleEngine }];
_vehicle addEventHandler ["Killed", { _this call ULP_fnc_onVehicleKilled }];
_vehicle addEventHandler ["Deleted", { _this call ULP_fnc_onVehicleDeleted }];
_vehicle addEventHandler ["RopeAttach", { _this call ULP_fnc_onVehicleRopeAttach }];
_vehicle addEventHandler ["HandleDamage", { _this call ULP_fnc_onVehicleHandleDamage }];
_vehicle addEventHandler ["Local", { _this call ULP_fnc_onVehicleLocal }];

private _textureActionsCfg = _cfg >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "Actions";

private _vehActions = if (isClass _textureActionsCfg) then {
	_textureActionsCfg
} else {
	_cfg >> "Actions"
};

if (isClass _vehActions) then {
	{ _vehicle removeAction _x; } forEach (_vehicle getVariable ["vehicle_actions", []]);

	private _actions = [];

	{
		_actions pushBackUnique (_vehicle addAction [getText (_x >> "actionTitle"), getText (_x >> "actionCode"), getArray (_x >> "params"), getNumber (_x >> "priority"), false, true, "", getText (_x >> "condition"), getNumber (_x >> "radius")]);
	} forEach ("isClass _x" configClasses _vehActions);

	if ((count _actions) > 0) then {
		_vehicle setVariable ["vehicle_actions", _actions];
	};
};

if (isNumber (_cfg >> "enableRope")) then {
	_vehicle enableRopeAttach ([getNumber (_cfg >> "enableRope")] call ULP_fnc_bool);
};

private _fuelConsumptionRateCoef =
	if (isNumber (_cfg >> "fuelConsumptionRate")) then {
		getNumber (_cfg >> "fuelConsumptionRate")
	} else {
		getFuelConsumptionCoef _vehicle
	};

if ([_vehicle, "EfficientEngineUpgrade"] call ULP_fnc_hasUpgrade) then {
	_fuelConsumptionRateCoef = _fuelConsumptionRateCoef - (_fuelConsumptionRateCoef * 0.3);
};

_vehicle setFuelConsumptionCoef _fuelConsumptionRateCoef;