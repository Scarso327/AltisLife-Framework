/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_switchBank";

if (canSuspend) exitWith {
    [ULP_fnc_switchBank, _this] call ULP_fnc_directCall;
};

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = (_index isEqualTo 1);

if (_group && { !([] call ULP_fnc_isGroup) }) exitWith {
	["You need to be in a group to access this!"] call ULP_fnc_hint;
	_ctrl lbSetCurSel 0;
	[_ctrl, 0] call ULP_fnc_switchBank;
};

private _balance = _display displayCtrl 4102;
private _transactionList = _display displayCtrl 4105;
lnbClear _transactionList;

{
	_x params ["_reason", "_in", "_out"];

	private _row = _transactionList lnbAddRow [
		_reason, 
		([format["£%1", [_in] call ULP_fnc_numberText], "-"] select (_in <= 0)),
		([format["£%1", [_out] call ULP_fnc_numberText], "-"] select (_out <= 0))
	];

	_transactionList lnbSetValue [[_row, 0], _forEachIndex];
	_transactionList lnbSetValue [[_row, 1], _in];
	_transactionList lnbSetValue [[_row, 2], _out];
} forEach + (profileNamespace getVariable ["ULP_Transactions", []]);

private _balValue = [BANK, [] call ULP_fnc_groupFunds] select (_group);

_balance ctrlSetStructuredText parseText format["<t align='left'>%1</t><t align='right'>%2%3</t><br/><t size='0.9'>Balance<t align='right'>Tax</t></t>", 
	([format["%1%2", "£", [_balValue] call ULP_fnc_numberText], "-"] select (_balValue <= 0)), (([] call ULP_fnc_groupTax) * 100), "%"
];

_display setVariable ["group", _group];