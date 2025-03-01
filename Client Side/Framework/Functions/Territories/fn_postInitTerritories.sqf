/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_postInitTerritories";

["Initialising Territories..."] call ULP_fnc_logIt;

private _territories = missionNamespace getVariable ["ULP_Territories", []];

if (_territories isEqualTo []) exitWith {};

{
	private _cfgName = _x getVariable ["config", configNull];
	[_x, _cfgName] call ULP_fnc_addCapture;

	nil
} count _territories;