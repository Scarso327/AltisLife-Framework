/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_createLayer";

_this params [
	["_name", "", [""]],
	["_type", "PLAIN", [""]],
	["_fadeInTime", 0, [0]],
	["_params", [], [[]]]
];

if !(isNull ([_name] call ULP_UI_fnc_getLayer)) exitWith { false };

_name cutRsc [_name, _type, _fadeInTime];

private _onInit = missionConfigFile >> "RscTitles" >> _name >> "onInit";
if (isText _onInit) then {
	private _layer = [_name] call ULP_UI_fnc_getLayer;
	[_layer, _params] call compile getText _onInit;
};

true