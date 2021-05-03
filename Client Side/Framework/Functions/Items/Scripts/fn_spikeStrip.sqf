/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_spikeStrip";

if !(isNull (objectParent player)) exitWith {
	["You must be outside of a vehicle..."] call ULP_fnc_hint;
};

if !(isNull (missionNamespace getVariable ["ULP_Spike", objNull])) exitWith {
	["You must place your current stringer before you can place another..."] call ULP_fnc_hint;
};

private _spike = createVehicle ["Land_Razorwire_F", [0, 0, 0]];
_spike attachTo [player, [0, 5.5, 0]];
_spike setDir 90;
_spike setVariable ["spike_owner", [getPlayerUID player, profileName], true];

ULP_Spike = _spike;

ULP_SpikePlaceAction = player addAction ["Place Stinger", {
	_this params ["", "", "_actionId"];

	private _spike = missionNamespace getVariable ["ULP_Spike", objNull];
	player removeAction _actionId;

	if (isNull _spike) exitWith {
		["An error occured while attempting to place this stringer..."] call ULP_fnc_hint;
	};

	["Placing Stringer", 2, [_spike], { !(isNull (_this select 0)) && { (["Stinger"] call ULP_fnc_hasItem) > 0 } }, {
		_this params [ "_spike" ];

		if (isNull _spike) exitWith {};
		
		if !(["Stinger", 1, true] call ULP_fnc_handleItem) exitWith {
			deleteVehicle _spike;
		};

		detach _spike;

		private _pos = getPosATL _spike;
		_pos set[2, 0];

		_spike setPosATL _pos;
		_spike setVectorUp surfaceNormal _pos;
		_spike setDamage 1;

		[_spike] remoteExecCall ["ULP_SRV_fnc_registerStinger", RSERV];

		["You have placed a stinger..."] call ULP_fnc_hint;
		ULP_Spike = nil;
	}, { deleteVehicle (_this select 0); }] call ULP_UI_fnc_startProgress;
}, nil, 10, false, false, "", "!(isNull (missionNamespace getVariable [""ULP_Spike"", objNull]))"];