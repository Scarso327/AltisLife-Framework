/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_validateField";

_this params [
	["_unit", objNull, [objNull]],
	["_sessiontotal", 0, [0]],
	["_total", 0, [0]],
	["_amount", 0, [0]],
	["_increase", true, [false]]
];

diag_log _this;

private _result = (([
	_sessiontotal - _amount,
	_sessiontotal + _amount
] select (_increase)) isEqualTo _total);

if !(_result) then {
	[format ["Field Validation Failed %1", _this]] call ULP_fnc_logIt;
	"qwerty12345" serverCommand format["#exec ban %1", owner _unit];
};

_result