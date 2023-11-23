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

if (_role isEqualTo "driver" && { !(isNull (_vehicle getVariable["siren", objNull])) }) then {
    [_vehicle, [], false] call ULP_fnc_vehicleSiren;
};

_unit setVariable ["seatbelt", false];

if ([] call ULP_UI_fnc_isProgress) then {
	[["RscProgress"] call ULP_UI_fnc_getLayer, false] call ULP_UI_fnc_endProgress;
};

true