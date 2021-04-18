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

if (isNull _vehicle || { _vehicle getVariable ["ready", false] }) exitWith {};
_vehicle setVariable ["ready", true];

if (local _vehicle) then {
	if (_jip) exitWith {};

	[_vehicle] call ULP_fnc_setVehicleAmmo;

	[_vehicle] remoteExecCall ["ULP_fnc_initVehicle", -clientOwner];

	_vehicle setVariable["jipReady", true, true];
};

_vehicle addEventHandler ["Engine", { _this call ULP_fnc_onVehicleEngine }];
_vehicle addEventHandler ["Killed", { _this call ULP_fnc_onVehicleKilled }];
_vehicle addEventHandler ["Deleted", { _this call ULP_fnc_onVehicleDeleted }];

private _vehActions = missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "Actions";

if (isClass _vehActions) then {
	{ _vehicle removeAction _x; } forEach (_vehicle getVariable ["vehicle_actions", []]);

	private _actions = [];

	{
		_actions pushBackUnique (_vehicle addAction [getText (_x >> "actionTitle"), getText (_x >> "actionCode"), getArray (_x >> "params"), getNumber (_x >> "priority"), true, true, "", getText (_x >> "condition"), getNumber (_x >> "radius")]);
	} forEach ("isClass _x" configClasses _vehActions);

	if ((count _actions) > 0) then {
		_vehicle setVariable ["vehicle_actions", _actions];
	};
};

if (isNumber (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "enableRope")) then {
	_vehicle enableRopeAttach ([getNumber (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "enableRope")] call ULP_fnc_bool);
};