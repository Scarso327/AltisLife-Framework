/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_grantTexture";

_this params [
	["_reward", configNull, [configNull]],
	["_values", [], [[]]]
];

private _message = "";

if (_values call ULP_fnc_isTextureUnlocked) then {
	// If they have it, we give money as reward...
	private _fallback = getArray (_reward >> "fallback");
	private _amount = round ((_fallback select 0) + (random (_fallback select 1)));

	[_amount, true, "Reward"] call ULP_fnc_addMoney;
	_message = format["%1%2", "£", [_amount] call ULP_fnc_numberText];
} else {
	private _cfg = [_values select 0] call ULP_fnc_vehicleCfg;

	_cfg params [
		"", "_missionCfg", "", "_name"
	];

	_values call ULP_fnc_unlockTexture;
	_message = format["%1 for the %2", getText (_missionCfg >> "Textures" >> (_values select 1) >> "displayName"), _name];
};

_message