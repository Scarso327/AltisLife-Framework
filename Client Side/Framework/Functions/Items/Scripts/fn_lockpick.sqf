/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_lockpick";

_this params [
	["_target", objNull, [objNull]]
];

private _hasLockpick = (["Lockpick"] call ULP_fnc_hasItem > 0);
private _hasSnap = (["SnapGun"] call ULP_fnc_hasItem > 0);

if (isNull _target || { !(_hasSnap ) && { !(_hasLockpick) } }) exitWith {
	if (dialog) then { closeDialog 0; };
	false
};

closeDialog 0;

private _time = round (40 + (random 25));
if (_hasSnap) then {_time = _time - (_time * 0.3)};

private _name = name _target;
private _isVehicle = false;

if ([_target, ["Car", "Air", "Ship", "Armored", "Submarine"]] call ULP_fnc_isKindOf) then {
	private _cfg = [typeOf _target] call ULP_fnc_vehicleCfg;
	if (_cfg isEqualTo []) exitWith { false breakOut "fn_lockpick"; };

	if (_target in ULP_Keys) exitWith {
		["You already have keys for this vehicle"] call ULP_fnc_hint;
		false breakOut "fn_lockpick";
	};

	if ([_target, "ImprovedLocksUpgrade"] call ULP_fnc_hasUpgrade) then {
		_time = _time + (_time * 0.5);
	};

	_name = _cfg param [3, "Vehicle"];
	_isVehicle = true;
} else {
	if !(_target isKindOf "Man") exitWith { false breakOut "fn_lockpick"; };

	if !([_target] call ULP_fnc_isRestrained) exitWith {
		["This person isn't restrained so no lock to pick"] call ULP_fnc_hint;
		false breakOut "fn_lockpick";
	};
};

_time = ["SpeedyLocksmith", _time] call ULP_fnc_activatePerk;

if ([] call ULP_fnc_isGroup) then {
	private _buff = [group player, "Lockpicking"] call ULP_fnc_groupBuff;
	if (_buff > 0) then { _time = _time - (_time * _buff); };
};

if !(_hasSnap) then { ["Lockpick", 1, true] call ULP_fnc_handleItem };

[format["Lockpicking %1", _name], _time, [_target, _name, _isVehicle], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_target", objNull, [objNull]],
		["_name", "Unknown", [""]],
		["_isVehicle", false, [true]]
	];
	
	if (isNull _target || { !(alive _target) }) exitWith {
		["You can't lockpick something that has been destroyed..."] call ULP_fnc_hint;
	};

	if (0.7 <= (random 1)) then {
		if (_isVehicle) exitWith {
			[getPlayerUID player, "TheftAct", "S25", 
				format [
					"Vehicle: %1 (%2)", _name, 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _target) >> "Textures" >> (_target getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
			
			[format ["You have successfully picked <t color='#B92DE0'>%1's</t> lock and gained forged keys...", _name]] call ULP_fnc_hint;
			ULP_Keys pushBackUnique _target;
			["LockpickVeh"] call ULP_fnc_achieve;
		};

		if !([_target] call ULP_fnc_isRestrained) exitWith {
			["This person is no longer restrained"] call ULP_fnc_hint;
		};

		[_target, player, false] remoteExecCall ["ULP_fnc_setRestrainedState", _target];
		[format ["You have successfully picked <t color='#B92DE0'>%1's</t> lock and released them...", _name]] call ULP_fnc_hint;
	} else {
		if (_isVehicle) then {
			[getPlayerUID player, "RoadsAct", "Section1", 
				format [
					"Attempted Lock Picking of Vehicle: %1 (%2)", _name, 
					getText (missionConfigFile >> "CfgVehicles" >> (typeOf _target) >> "Textures" >> (_target getVariable ["texture", ""]) >> "displayName")
				]
			] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
		};

		["The lockpick broke while attempting to pick the lock..."] call ULP_fnc_hint;
	};
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;