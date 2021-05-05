/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_robMoney";

if (canSuspend) exitWith {
    [ULP_fnc_robMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_mode", 0, [0]],
	["_params", [], []]
];

switch (_mode) do {
	case 2: {
		_params params [
			["_unit", objNull, [objNull]],
			["_cash", 0, [0]]
		];

		if (isNull _unit || { _unit isEqualTo player }) exitWith {};
		
		if (_cash > 0 && { [_cash, false, format ["%2 %1", name _unit, ["Robbed", "Seized"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_addMoney }) then {
			[format ["You %4 %1 for %2%3", [_unit, true] call ULP_fnc_getName, "£", [_cash] call ULP_fnc_numberText, ["robbed", "seized"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
			_unit setVariable ["robbing", nil];
		} else {
			[format ["%1 had no money to %2...", [_unit, true] call ULP_fnc_getName, ["rob", "seize"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
		};
	};

	_params params [
		["_unit", objNull, [objNull]]
	];

	if (isNull _unit || { _unit isEqualTo player }) exitWith {};

	case 1: {
		private _cash = + CASH;
		if (_cash > 0 && { [_cash, false, format ["%2 By %1", name _unit, ["Robbed", "Seized"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_removeMoney }) then {
			[format ["%1 has %4 you for %2%3", [_unit, true] call ULP_fnc_getName, "£", [_cash] call ULP_fnc_numberText, ["robbed", "seized"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
		};

		_unit setVariable ["robbed_me", time];

		[2, [player, _cash]] remoteExecCall ["ULP_fnc_robMoney", _unit];
	};

	default {
		if (_unit getVariable ["robbing", false]) exitWith {
			[format ["You're already %1 this person...", ["robbing", "seizing"] select ([_unit, ["Police"]] call ULP_fnc_isFaction)]] call ULP_fnc_hint;
		};
		_unit setVariable ["robbing", true];
		_unit setVariable ["robbed_by_me", time];
		
		[1, [player]] remoteExecCall ["ULP_fnc_robMoney", _unit];
	};
};