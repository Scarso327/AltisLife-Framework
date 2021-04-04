/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_activatePerk";

_this params [
	["_perk", "", [""]],
	["_params", []],
	["_increase", true, [false]]
];

if !([_perk] call ULP_fnc_hasPerk) exitWith { _params };

private _level = [_perk] call ULP_fnc_getPerkLevel;

_params = call {
	_level params [
		"_level", "_xp"
	];

	private _bonus = [_perk] call ULP_fnc_getPerkBonus;

	call compile getText (missionConfigFile >> "CfgPerks" >> _perk >> "onActivated");
};

if (_increase) then {
	[_perk, round (random 5)] call ULP_fnc_addPerkXP;
};

_params