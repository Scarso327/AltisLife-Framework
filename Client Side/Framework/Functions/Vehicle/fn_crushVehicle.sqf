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
	hint "Only Police can crush vehicles...";
};

if !((crew _vehicle) isEqualTo []) exitWith {
	hint "No one can be in the vehicle while you crush it...";
};

private _time = getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "crushTime");
if (isNumber (_missionCfg >> "crushTime")) then {
	_time = _time + getNumber (_missionCfg >> "crushTime");
};

if !([format["Crushing %1", _name], _time, [_vehicle, _name, _fee], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fee" ];

	if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
		hint format["You failed to crush this vehicle as either someone was in it or it's already been removed..."];
	};

	private _id = _vehicle getVariable ["vehicle_id", -1];
	if (_id >= 0) then {
		[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];
	};

	deleteVehicle _vehicle;
	hint "Vehicle has been crushed.";
}, {}] call ULP_UI_fnc_startProgress) exitWith {
	hint "You can't crush a vehicle while performing another action...";
};

closeDialog 0;