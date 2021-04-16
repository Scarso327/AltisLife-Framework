/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_dropMoney";

if (canSuspend) exitWith {
    [ULP_fnc_dropMoney, _this] call ULP_fnc_directCall;
};

if !(_this params [
    ["_pos", [], [[]]]
]) exitWith { false };

private _cash = + CASH;

if (_cash > 0 && { [_cash, false, "Died"] call ULP_fnc_removeMoney }) exitWith {
	private _money = createSimpleObject [(switch (true) do {
		case (_cash <= 1000) : { "Land_MoneyBills_01_bunch_F" };
		case (_cash <= 300000) : { "Land_MoneyBills_01_roll_F" };
		default { "Land_MoneyBills_01_stack_F" };
	}), AGLtoASL _pos];
	_money setDir (random 360);

	_money setVariable ["ULP_MoneyStack", _cash, true];
	true
};

false