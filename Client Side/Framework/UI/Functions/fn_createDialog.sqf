/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_createDialog";

_this params [
	["_name", "", [""]],
	["_params", [], [[]]]
];

if !(createDialog _name) exitWith { false };

private _onInit = missionConfigFile >> _name >> "onInit";
if (isText _onInit) then {
	private _layer = [_name] call ULP_UI_fnc_getLayer;
	[_layer, _params] call compile getText _onInit;
};

true