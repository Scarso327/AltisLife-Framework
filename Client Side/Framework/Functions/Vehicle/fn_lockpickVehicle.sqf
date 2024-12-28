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

private _time = ["SpeedyLocksmith", round (40 + (random 25))] call ULP_fnc_activatePerk;

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Lockpicking"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

[format["Lockpicking %1", (_cfg param [3, "Vehicle"])], _time, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", [], [[]]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["This vehicle is too far gone to be lockpicked..."] call ULP_fnc_hint;
	};

	if (_vehicle in ULP_Keys) exitWith {
		["You already have keys for this vehicle"] call ULP_fnc_hint;
	};

	if (["Lockpick", 1, true] call ULP_fnc_handleItem) then {
		if (0.7 <= (random 1)) then {
			[getPlayerUID player, "Theft", "Section12", 
				format [
					"Vehicle: %1 (%2)", 
					([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "Unknown"], 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];

			[format ["You have successfully picked <t color='#B92DE0'>%1's</t> lock and gained forged keys...", _cfg param [3, "vehicle"]]] call ULP_fnc_hint;
			ULP_Keys pushBackUnique _vehicle;
		} else {
			[getPlayerUID player, "CriminalAttempts", "Section1", 
				format [
					"Attempted Lock Picking of Vehicle: %1 (%2)", 
					([typeOf _vehicle] call ULP_fnc_vehicleCfg) param [3, "Unknown"], 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _vehicle) >> "Textures" >> (_vehicle getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];

			["The lockpick broke while attempting to pick the lock..."] call ULP_fnc_hint;
		};
	} else {
		["You lost your lockpick while picking the vehicle and so couldn't finish picking..."] call ULP_fnc_hint;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;