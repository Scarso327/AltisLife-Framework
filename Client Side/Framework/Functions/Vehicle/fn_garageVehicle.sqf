/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_garageVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};

private _time = getNumber (missionConfigFile >> "CfgSettings" >> "garageDelay");
if (isNumber (_missionCfg >> "garageDelay")) then {
	_time = _time + getNumber (_missionCfg >> "garageDelay");
};

if !((crew _vehicle) isEqualTo []) exitWith {
	hint "No one can be in the vehicle while you store it...";
};

if !([format["Storing %1", _name], _time, [_vehicle, _name], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name" ];

	if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
		hint format["You failed to store this vehicle as either someone was in it or it's already been removed..."];
	};

	private _id = _vehicle getVariable ["vehicle_id", -1];
	if (_id >= 0) then {
		["VehicleStored", { hint "Vehicle has been stored."; }, true] call ULP_fnc_addEventHandler;
		[_vehicle] remoteExecCall ["ULP_SRV_fnc_storeVehicle", RSERV];
	} else {
		deleteVehicle _vehicle;
		hint "Vehicle has been stored.";
	};
}, {}] call ULP_UI_fnc_startProgress) exitWith {
	hint "You can't impound a vehicle while performing another action...";
};

closeDialog 0;