/*
** Author: Jack "Scarso" Farhall
** Description: Allows the removal of a clamp from a vehicle if the player is Police or HATO
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeVehicleClamp";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

private _clamp = _vehicle getVariable ["clamp_fine", []];

if (_clamp isEqualTo []) exitWith {
	["This vehicle has no clamp..."] call ULP_fnc_hint;
	false
};

if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["Only the Police or HATO can remove clamps..."] call ULP_fnc_hint;
	false
};

private _profileName = _clamp param [0, "Unknown"];

closeDialog 0;

[format["Removing %1's Clamp on %2", _profileName, (_cfg param [3, "Vehicle"])], 30, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", configNull, [configNull]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["This vehicle is too far gone..."] call ULP_fnc_hint;
	};

	_vehicle setVariable ["clamp_fine", nil, true];
	[format ["You have removed the clamp from <t color='#B92DE0'>%1</t>...", _cfg param [5, "Vehicle"]]] call ULP_fnc_hint;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

true