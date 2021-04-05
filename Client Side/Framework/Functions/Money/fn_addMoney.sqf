/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addMoney";

if (canSuspend) exitWith {
    [ULP_fnc_addMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_amount", 0, [0]],
	["_isBank", false, [true]],
	["_transaction", "Unknown", [""]]
];

_amount = round _amount;
if (_amount <= 0) exitWith { false };

if (_isBank) then {
	BANK = BANK + _amount;
	[player, 2, [BANK, _amount, true, _transaction]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

	[_amount, 0, _transaction] call ULP_fnc_logTransaction;
} else {
	CASH = CASH + _amount;
	[player, 1, [CASH, _amount, true, _transaction]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

if (BANK >= 1000000) then { ["OneMillion"] call ULP_fnc_achieve; };
if (BANK >= 10000000) then { ["TenMillion"] call ULP_fnc_achieve; };
if (BANK >= 100000000) then { ["HundredMillion"] call ULP_fnc_achieve; };

["MoneyChanged", [CASH, BANK]] call ULP_fnc_invokeEvent;
true