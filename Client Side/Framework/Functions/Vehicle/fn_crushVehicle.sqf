/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_crushVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};
if !([player, ["Police"]] call ULP_fnc_isFaction) exitWith {
	["Only Police can crush vehicles!"] call ULP_fnc_hint;
};

if !((crew _vehicle) isEqualTo []) exitWith {
	["No one can be in the vehicle while you crush it!"] call ULP_fnc_hint;
};

if ((_vehicle getVariable ["vehicle_id", -1]) < 0) exitWith {
	["Rentals can't be crushed!"] call ULP_fnc_hint;
};

private _time = ["StreetCleaner", getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "crushTime")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "crushTime")) then {
	_time = _time + getNumber (_missionCfg >> "crushTime");
};

if !([format["Crushing %1", _name], _time, [_vehicle, _name, _fee], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fee" ];

	if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
		[format["You failed to crush this vehicle as either someone was in it or it's already been removed!"]] call ULP_fnc_hint;
	};

	private _id = _vehicle getVariable ["vehicle_id", -1];
	if (_id >= 0) then {
		[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];
	};

	private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

	deleteVehicle _vehicle;

	[player, "CrushVehicle"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

	["FirstCrush"] call ULP_fnc_achieve;

	["Vehicle has been crushed!"] call ULP_fnc_hint;
	["Crushed", [_owner param [0, "Someone"], _name, [player, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
}, {}] call ULP_UI_fnc_startProgress) exitWith {
	["You can't crush a vehicle while performing another action!"] call ULP_fnc_hint;
};

closeDialog 0;