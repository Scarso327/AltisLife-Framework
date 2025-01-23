/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onGetOut";

_this params [
	["_unit", objNull, [objNull]],
	["_role", "", [""]],
	["_vehicle", objNull, [objNull]],
	["_turret", [], [[]]]
];

if ([_unit] call ULP_fnc_isRestrained && { ((_unit getVariable ["restrained_in_vehicle", objNull]) isEqualTo _vehicle) }) exitWIth {
	_unit moveInCargo _vehicle;
};

if (_role isEqualTo "driver" && { !(isNull (_vehicle getVariable["siren", objNull])) }) then {
    [_vehicle, [], false] call ULP_fnc_vehicleSiren;
};

_unit setVariable ["seatbelt", false];

if ([] call ULP_UI_fnc_isProgress) then {
	[["RscProgress"] call ULP_UI_fnc_getLayer, false] call ULP_UI_fnc_endProgress;
};

if ([["EnableAutoChatSwitch"] call ULP_fnc_getOption] call ULP_fnc_bool && { currentChannel isEqualTo 4 }) then {
	setCurrentChannel 5;
};

[] call ULP_fnc_setViewDistance;

if !(cameraView isEqualTo "GUNNER" && { [goggles _unit] call ULP_fnc_isNightVision }) then {
	private _action = if ((currentVisionMode _unit) isEqualTo 0) then { "nvGogglesOff" } else { "nvGoggles" };
    _unit action [_action, _unit];
};

true