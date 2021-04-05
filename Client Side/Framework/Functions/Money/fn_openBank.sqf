/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openBank";

if (dialog) exitWith {};

if (createDialog "DialogMoney") then {
	private _display = findDisplay 4100;
	if (isNull _display) exitWith {};

	private _list = _display displayCtrl 4105;
	private _filter = _display displayCtrl 4104;

	[_filter, _list, [0, 1, 2], 4115] call BIS_fnc_initListNBoxSorting;

	_display setVariable ["trans_event", (["TransactionsUpdated", {
		private _display = findDisplay 4100;
		if (isNull _display) exitWith {
			["TransactionsUpdated", _x] call ULP_fnc_removeEventHandler;
		};

		private _toolbox = _display displayCtrl 4101;

		if ((lbCurSel _toolbox) isEqualTo 1) then {
			[_toolbox, 1] call ULP_fnc_switchBank;
		};
	}] call ULP_fnc_addEventHandler)];

	_display setVariable ["money_event", (["MoneyChanged", {
		private _display = findDisplay 4100;
		if (isNull _display) exitWith {
			["MoneyChanged", _x] call ULP_fnc_removeEventHandler;
		};

		private _toolbox = _display displayCtrl 4101;

		if ((lbCurSel _toolbox) isEqualTo 0) then {
			[_toolbox, 0] call ULP_fnc_switchBank;
		};
	}] call ULP_fnc_addEventHandler)];

	_display setVariable ["gang_event", (["GroupMoneyChanged", {
		private _display = findDisplay 4100;
		if (isNull _display) exitWith {
			["GroupMoneyChanged", _x] call ULP_fnc_removeEventHandler;
		};

		private _toolbox = _display displayCtrl 4101;

		if ((lbCurSel _toolbox) isEqualTo 1) then {
			[_toolbox, 1] call ULP_fnc_switchBank;
		};
	}] call ULP_fnc_addEventHandler)];
	
	[(_display displayCtrl 4101), 0] call ULP_fnc_switchBank;
};