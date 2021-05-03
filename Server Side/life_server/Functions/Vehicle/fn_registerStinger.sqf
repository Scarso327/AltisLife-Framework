/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_registerStinger";

_this params [
	["_spike", objNull, [objNull]]
];

if (isNull _spike) exitWith {};

[_spike, {
	if (isNil "_this" || { isNull _this }) exitWith {
		[_thisEventHandler] call ULP_fnc_removeEachFrame;
	};

	private _vehicle = nearestObjects [getPos _this, ["Car"], 5] param [0, objNull];
	if (isNull _vehicle) exitWith {};

	deleteVehicle _this;
	[_thisEventHandler] call ULP_fnc_removeEachFrame;
	
	[_this] remoteExecCall ["ULP_fnc_spikeVehicle", _vehicle];
}] call ULP_fnc_addEachFrame;