/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_checkMoney";

if (canSuspend) exitWith {
    [ULP_fnc_checkMoney, _this] call ULP_fnc_directCall;
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
		
		if (_cash > 0) then {
			[format ["%1 has %2%3 in cash on their person...", [_unit, true] call ULP_fnc_getName, "£", [_cash] call ULP_fnc_numberText]] call ULP_fnc_hint;
			_unit setVariable ["checking_money", nil];
		} else {
			[format ["%1 has no cash on them...", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
		};
	};

	case 1: {
		_params params [
			["_unit", objNull, [objNull]]
		];

		if (isNull _unit || { _unit isEqualTo player }) exitWith {};
		
		[2, [player, CASH]] remoteExecCall ["ULP_fnc_checkMoney", _unit];
	};

	default {
		_params params [
			["_unit", objNull, [objNull]]
		];

		if (isNull _unit || { _unit isEqualTo player }) exitWith {};
		
		if (_unit getVariable ["checking_money", false]) exitWith {
			["You're already counting this person's money..."] call ULP_fnc_hint;
		};
		_unit setVariable ["checking_money", true];
		
		[1, [player]] remoteExecCall ["ULP_fnc_checkMoney", _unit];
	};
};