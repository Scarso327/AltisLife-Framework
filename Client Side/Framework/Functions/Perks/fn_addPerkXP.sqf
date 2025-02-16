/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addPerkXP";

_this params [
	["_perk", "", [""]],
	["_amount", 1, [0]]
];

if !([_perk] call ULP_fnc_hasPerk) exitWith { false };

private _cfg = missionConfigFile >> "CfgPerks" >> _perk >> "Leveling";
if !(isClass _cfg) exitWith { false };

// Stops easy spam leveling by adding a mini cooldown...
private _recentIncreases = + (missionNamespace getVariable ["ULP_PerksXP", createHashMap]);
if (time < (_recentIncreases getOrDefault [_perk, time])) exitWith { false };
_recentIncreases set [_perk, time + (random 8)];
missionNamespace setVariable ["ULP_PerksXP", _recentIncreases];

private _requirement = getNumber (_cfg >> "xpLevel");
private _max = getNumber (_cfg >> "maxLevel");

([_perk] call ULP_fnc_getPerkLevel) params [
	"_level", "_xp"
];

private _previousLevel = _level;
_xp = _xp + _amount;

for "_i" from 0 to 1 step 0 do {
	if (_xp < _requirement || { _level isEqualTo _max }) exitWith {};
	_xp = _xp - _requirement;
	_level = _level + 1;
};

// "Clamp" them...
_level = (_level max 0) min _max;
_xp = (_xp max 0) min _requirement;

if (_previousLevel < _level) then {
	["You leveled up a perk!"] call ULP_fnc_hint;
};

ULP_Perks set [_perk, [_level, _xp]];
[player, 11, ULP_Perks] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
true