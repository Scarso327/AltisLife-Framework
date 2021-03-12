/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addXP";

_this params [
	["_xp", 1, [0]],
	["_reason", "doing something...", [""]],
	["_chance", 100, [0]]
];

if ((random 100) > _chance || { _xp < 1 }) exitWith { false };

private _required = [ULP_Level] call ULP_fnc_getRequiredXP;
private _max = [] call ULP_fnc_getMaxLevel;

ULP_XP = round(ULP_XP + _xp);

private _previousLevel = ULP_Level;

for "_i" from 0 to 1 step 0 do {
	scopeName "fn_addXP_rankLoop";

	if (ULP_XP < _required) exitWith {};

	if (ULP_XP >= _required) then {
		if (ULP_Level isEqualTo _max) then {
			ULP_XP = _required;
			breakOut "fn_setPlayerInfo_rankLoop";
		} else {
			ULP_XP = ULP_XP - _required;
			ULP_Level = ULP_Level + 1;
			_required = [ULP_Level] call ULP_fnc_getRequiredXP;
		};
	};
};

// We leveled up...
if !(ULP_Level isEqualTo _previousLevel) then {
	hint "You leveled up";
} else {
	hint format["You gained %1 XP for %2", [_xp] call ULP_fnc_numberText, _reason];
};

[player, 4, [ULP_Level, ULP_XP]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];