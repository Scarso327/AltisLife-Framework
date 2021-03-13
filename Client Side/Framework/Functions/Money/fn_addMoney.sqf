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
	[player, 2, BANK] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
} else {
	CASH = CASH + _amount;
	[player, 1, CASH] remoteExecCall ["ULP_SRV_fnc_savePlayerState", RSERV];
};

["MoneyChanged", [CASH, BANK]] call ULP_fnc_invokeEvent;
true