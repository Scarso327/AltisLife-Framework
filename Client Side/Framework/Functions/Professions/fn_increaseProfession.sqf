/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_increaseProfession";

_this params [
	["_profession", "", [""]],
	["_amount", 1, [0]],
	["_chance", 5, [0]]
];

if ((random 100) > _chance) exitWith { false };

private _cfg = missionConfigFile >> "CfgProfessions" >> _profession;
if (!(isClass _cfg) || { _amount < 1 }) exitWith { false };

private _requirement = getNumber (_cfg >> "xpLevel");
private _max = getNumber (_cfg >> "maxLevel");

(ULP_Professions getOrDefault [_profession, [0, 0]]) params [
	"_level", "_points"
];

if (_level > 0) then {
	_requirement = _requirement * (getNumber (_cfg >> "xpMultipler") * _level);
};

private _previousLevel = _level;
_points = _points + _amount;

for "_i" from 0 to 1 step 0 do {
	if (_points < _requirement || { _level isEqualTo _max }) exitWith {};
	_points = _points - _requirement;
	_level = _level + 1;
};

// "Clamp" them...
_level = (_level max 0) min _max;
_points = (_points max 0) min _requirement;

if (_previousLevel < _level) then {
	hint "You leveled up a profession";
} else {
	hint "You've increased a profession";
};

ULP_Professions set [_profession, [_level, _points]];
[player, 3, ULP_Professions] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

true