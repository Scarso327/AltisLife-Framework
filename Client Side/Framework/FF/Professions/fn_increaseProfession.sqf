/*
	@File: fn_increaseProfession.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Increases the value of the given profession.

	@Parameters:
		0 - TYPE: STRING - DES: Name of the profession class
		1 - TYPE: INTGER - DES: The amount we're either decreasing or increasing by
		2 - TYPE: INTGER - DES: The chance of increasing our profession
		3 - TYPE: INTGER - DES: 0: Increase 1: Decrease
*/
#include "..\..\script_macros.hpp"
params [
	["_prof", "", [""]],
	["_val", 0, [0]],
	["_chance", 100, [0]],
	["_mode", 0, [0]]
];

if (_prof isEqualTo "") exitWith {};
if (_val isEqualTo 0) exitWith {};
if (_mode < 0 || _mode > 1) exitWith {};

if !(isClass (missionConfigFile >> "CfgProfessions" >> _prof)) exitWith { systemChat "Profession does not exist." };

private _levelUp = false;

// Get Profession Info...
private _displayName = M_CONFIG(getText,"CfgProfessions",_prof,"displayName");
private _maxLevel = M_CONFIG(getNumber,"CfgProfessions",_prof,"maxLevel");
private _varName = PROF_VARNAME(_prof);
private _curLevel = PROF_VALUE(_prof);

if (_curLevel isEqualTo _maxLevel) exitWith { SVAR_MNS [_varName,_maxLevel]; }; // Don't increase our level if we're already maxed out!

// Is our chance good?
if (_chance >= 100) then { _levelUp = true; } else {	
	if ((floor (random 100)) <= _chance) then {	_levelUp = true; };
};

// If we did get the correct chance of a level change then subtract or add the value.
private _newLevel = 0;
if (_levelUp) then {
	_newLevel = _curLevel;

	switch (_mode) do {
		case 0: {
			_newLevel = _newLevel + _val;
			if (_newLevel >= _maxLevel) then {_newLevel = _maxLevel};
		};
		case 1: {
			_newLevel = _newLevel - _val;
			if (_newLevel <= 0) then {_newLevel = 0};
		};
	};

	SVAR_MNS [_varName,_newLevel]; // Set the variable...
	[] call SOCK_fnc_updateRequest; // Force Sync!
};