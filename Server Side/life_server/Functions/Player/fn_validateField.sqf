/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_validateField";

_this params [
	["_unit", objNull, [objNull]],
	["_sessionTotal", 0, [0]],
	["_total", 0, [0]],
	["_amount", 0, [0]],
	["_increase", true, [false]]
];

private _resultTotal = 
	if (_increase) then {
		_sessionTotal + _amount
	} else {
		_sessionTotal - _amount
	};

private _result = (_resultTotal isEqualTo _total);

if !(_result) then {
	[format ["Failed to validate session values for %1. Session Total: %2, Total After Change: %3, Change Amount: %4, Change Type: %5, Actual Result: %6", 
		getPlayerUID _unit, 
		[_sessionTotal] call ULP_fnc_numberText,
		[_total] call ULP_fnc_numberText,
		[_amount] call ULP_fnc_numberText,
		_increase,
		[_resultTotal] call ULP_fnc_numberText
	]] call ULP_fnc_logIt;

	if !(getText (configFile >> "CfgPatches" >> "ULPServer" >> "serverCommandPassword") serverCommand format["#exec ban ""%1 Cheating""", owner _unit]) then {
		[format ["Failed to kick %1 for validate session validation", getPlayerUID _unit]] call ULP_fnc_logIt;
	};
};

_result