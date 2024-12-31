/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_fuelCan";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "", "", "", "", "_fuel"
];

if !(isClass _missionCfg) exitWith {};

private _time = 40;
if (isNumber (_missionCfg >> "refuelTime")) then {
	_time = _time + getNumber (_missionCfg >> "refuelTime");
};

if !([format["Refueling %1", _name], _time, [_vehicle, _name, _fuel], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { ["FuelCan"] call ULP_fnc_hasItem > 0 } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fuel" ];

	if (isNull _vehicle || { !(alive _vehicle) } || { !(["FuelCan", 1, true] call ULP_fnc_handleItem) }) exitWith {
		[format["You failed to refuel the <t color='#B92DE0'>%1</t> as it's either extremely damaged or you lost your fuel can..."]] call ULP_fnc_hint;
	};

	_fuel = ((fuel _vehicle) + (_fuel / 100));
	
	if (local _vehicle) then {
		_vehicle setFuel _fuel;
	} else {
		[_vehicle, _fuel] remoteExecCall ["ULP_fnc_setFuel", _vehicle];
	};

	[format["You've refueled <t color='#B92DE0'>%1</t> using a fuel can...", _name]] call ULP_fnc_hint;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["You can't refuel a vehicle while performing another action!"] call ULP_fnc_hint;
};

closeDialog 0;