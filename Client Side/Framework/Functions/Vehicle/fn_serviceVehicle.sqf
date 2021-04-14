/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_serviceVehicle";

if (canSuspend) exitWith {
    [ULP_fnc_serviceVehicle, _this] call ULP_fnc_directCall;
};

_this params [
	["_location", objNull, [objNull]]
];

if (isNull _location) exitWith {};

private _near = _location nearEntities [["Air"], 15];
private _vehicle = _near param [(_near findIf { [player, _x] call ULP_fnc_isVehicleOwner }), objNull];

if (isNil "_vehicle" || { isNull _vehicle } || { !(alive _vehicle) }) exitWith {
	["No air vehicles near stand to service!"] call ULP_fnc_hint;
};

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [
	"", "_missionCfg", "", "_name", "", "", "", "", "_fuel"
];

private _time = 15;
if (isNumber (_missionCfg >> "serviceTime")) then {
	_time = _time + getNumber (_missionCfg >> "serviceTime");
};

private _cost = round (1000 * (_fuel / 10));
if (isNumber (_missionCfg >> "serviceCost")) then {
	_cost = _cost + getNumber (_missionCfg >> "serviceCost");
};

if (CASH < _cost) exitWith {
	[format ["You can't afford to pay %1%2 to service this vehicle!", "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

if !([format["Servicing %1", _name], _time, [_location, _vehicle, _name, _cost], {
	!(isNull (_this select 0)) && { alive (_this select 1) } && { ((_this select 0) distance (_this select 1)) <= 15 }
}, {
	_this params [ "_location", "_vehicle", "_name", "_cost" ];

	if (isNull _vehicle || { !(alive _vehicle) } || { (_location distance _vehicle) > 15 }) exitWith {
		[format ["You failed to service the %1 as it's either beyond repair or isn't near the stand!", _name]] call ULP_fnc_hint;
	};

	if ([_cost] call ULP_fnc_removeMoney) exitWith {
		[format ["You can't afford to pay %1%2 to service this vehicle.!", "£", [_cost] call ULP_fnc_numberText]] call ULP_fnc_hint;
	};

	[_vehicle, 1] remoteExecCall ["ULP_fnc_setFuel", _vehicle];
	_vehicle setDamage 0;

	[format ["You've serviced %1.", _name]] call ULP_fnc_hint;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["You can't service a vehicle while performing another action!"] call ULP_fnc_hint;
};