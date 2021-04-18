/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_lockpickVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] } || { ((["Lockpick"] call ULP_fnc_hasItem) < 1) }) exitWith { if (dialog) then { closeDialog 0; }; };

closeDialog 0;

if (_vehicle in ULP_Keys) exitWith {
	["You already have keys for this vehicle"] call ULP_fnc_hint;
};

private _time = round (40 + (random 25));

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Lockpicking"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

[format["Lockpicking %1", (_cfg param [3, "Vehicle"])], _time, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", configNull, [configNull]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["This vehicle is too far gone to be lockpicked..."] call ULP_fnc_hint;
	};

	if (_vehicle in ULP_Keys) exitWith {
		["You already have keys for this vehicle"] call ULP_fnc_hint;
	};

	if (["Lockpick", 1, true] call ULP_fnc_handleItem) then {
		if (0.7 <= (random 1)) then {
			[format ["You have successfully picked %1's lock and gained forged keys..."]] call ULP_fnc_hint;
			ULP_Keys pushBackUnique _x;
		} else {
			["The lockpick broke while attempting to pick the lock..."] call ULP_fnc_numberText;
		};
	} else {
		["You lost your lockpick while picking the vehicle and so couldn't finish picking..."] call ULP_fnc_numberText;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;