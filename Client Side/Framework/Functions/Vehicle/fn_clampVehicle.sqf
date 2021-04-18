/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_clampVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] } || { ((["VehicleClamp"] call ULP_fnc_hasItem) < 1) }) exitWith { if (dialog) then { closeDialog 0; }; };

private _clamp = _vehicle getVariable ["clamp_fine", []];

if !(_clamp isEqualTo []) exitWith {
	["This vehicle has already been clamped..."] call ULP_fnc_hint;
	false
};

if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["You must be Police or HATO to use clamps..."] call ULP_fnc_hint;
	false
};

closeDialog 0;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (missionConfigFile >> "CfgSettings" >> "Police" >> "clampFee"), [_vehicle, _cfg],
	{
		_this params [
			["_vehicle", objNull, [objNull]],
			["_cfg", [], [[]]],
			["_display", displayNull, [displayNull]],
			["_fine", 1, [0]]
		];

		[format["Clamping %1", (_cfg param [3, "Vehicle"])], 30, [_vehicle, _cfg, _fine], { (player distance (_this select 0)) <= 5 }, {
			_this params [
				["_vehicle", objNull, [objNull]],
				["_cfg", configNull, [configNull]],
				["_fine", 1, [0]]
			];
			
			if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
				["This vehicle is too far gone to be clamped..."] call ULP_fnc_hint;
			};

			if (["VehicleClamp", 1, true] call ULP_fnc_handleItem) then {
				_vehicle setVariable ["clamp_fine", [profileName, getPlayerUID player, _fine], true];
				[format ["You have clamped %1 for %2%3...", _cfg param [5, "Vehicle"], "£", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;
			} else {
				["You need a clamp to clamp a vehicle..."] call ULP_fnc_numberText;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, false, "format [""%1%2"", ""£"", [_this] call ULP_fnc_numberText]", false
] call ULP_fnc_selectNumber;

true