/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sendMoney";

if (canSuspend) exitWith {
    [ULP_fnc_sendMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", objNull, [objNull]],
	["_amount", 0, [0]],
	["_bank", false, [true]]
];

if (isNull _unit || { _unit isEqualTo player } || { [] call ULP_fnc_isRestrained } || { [] call ULP_fnc_isSurrendered } || { isDowned(player) } || { isDowned(_unit) } || { !_bank && ((player distance _unit) > 3) }) exitWith {
	["You have to be close, unrestrained and not surrendering to give cash..."] call ULP_fnc_hint;
};

if (_bank && { [] call ULP_fnc_isHobo }) exitWith {
	["You don't meet the requirements to wire transfer money"] call ULP_fnc_hint;
};

if (_amount < 1) exitWith {
	["You have no money to give at this time..."] call ULP_fnc_hint;
};

if !([_amount, _bank, format ["%1 %2", ["Given to", "Transferred to"] select (_bank), name _unit]] call ULP_fnc_removeMoney) exitWith {
	[format ["You don't have <t color='#B92DE0'>%1%2</t> to %3...", "£", [_amount] call ULP_fnc_numberText, ["give", "transfer"] select (_bank)]] call ULP_fnc_hint;
};

[player, _amount, _bank] remoteExecCall ["ULP_fnc_recieveMoney", _unit];
[format ["You have %1 <t color='#B92DE0'>%2%3</t> to %4", ["given", "transferred"] select (_bank), "£", [_amount] call ULP_fnc_numberText, name _unit]] call ULP_fnc_hint;