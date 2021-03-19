/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeMoney";

if (canSuspend) exitWith {
    [ULP_fnc_removeMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_amount", 0, [0]],
	["_isBank", false, [true]],
	["_transaction", "Unknown", [""]]
];

_amount = round _amount;
if (_amount <= 0) exitWith { true };

if (_isBank) then {
	if (BANK < _amount) exitWith { false breakOut "fn_removeMoney"; };

	BANK = BANK - _amount;
	[player, 2, [BANK, _amount, false]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];

	[0, _amount, _transaction] call ULP_fnc_logTransaction;
} else {
	if (CASH < _amount) exitWith { false breakOut "fn_removeMoney"; };

	CASH = CASH - _amount;
	[player, 1, [CASH, _amount, false]] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

["MoneyChanged", [CASH, BANK]] call ULP_fnc_invokeEvent;
true