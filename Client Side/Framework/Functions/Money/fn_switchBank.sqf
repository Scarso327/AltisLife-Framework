/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_switchBank";

_this params [
	"_ctrl", "_index"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = (_index isEqualTo 1);

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

private _balValue = [BANK, 0] select (_group);

_balance ctrlSetStructuredText parseText format["<t align='left'>%1</t><t align='right'>1.5%</t><br/><t size='0.9'>Balance<t align='right'>Tax</t></t>", 
	([format["%1%2", "£", [_balValue] call ULP_fnc_numberText], "-"] select (_balValue <= 0))
];

_display setVariable ["group", _group];