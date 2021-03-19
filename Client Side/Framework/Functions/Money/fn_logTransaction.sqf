/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_logTransaction";

_this params [
	["_in", 0, [0]],
	["_out", 0, [0]],
	["_reason", "", [""]]
];

if (_reason isEqualTo "" || { _in <= 0 && _out <=0 }) exitWith { false };

private _history = + (profileNamespace getVariable ["ULP_Transactions", []]);
_history pushBack [_reason, _in, _out];

private _count = count _history;
if (_count > 100) then {
	_history = _history select [_count - 100, 100];
};

profileNamespace setVariable ["ULP_Transactions", _history];
saveProfileNamespace;

["TransactionsUpdated", _history] call ULP_fnc_invokeEvent;
true