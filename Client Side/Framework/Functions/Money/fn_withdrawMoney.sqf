/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_withdrawMoney";

if (canSuspend) exitWith {
    [ULP_fnc_withdrawMoney, _this] call ULP_fnc_directCall;
};

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = _display getVariable ["group", false];

if (_group && { !([1] call ULP_fnc_canGroupRank) }) exitWith {
	["You don't have permission to withdraw from group funds!"] call ULP_fnc_hint;
};

private _amount = ([BANK, [] call ULP_fnc_groupFunds] select (_group));
if (_amount <= 0) exitWith {
	["You don't have anything to withdraw!"] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_group],
	{
		_this params [
			["_group", false, [true]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		if (_group) then {
			[format ["Attempting to withdraw %1%2...", "£", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
			[player, _value] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
		} else {
			if (_value > BANK) exitWith {
				[format["You don't have <t color='#B92DE0'>%1%2</t> to withdraw!", "£", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};

			if ([_value, true, "Bank Withdrawal"] call ULP_fnc_removeMoney) then {
				[_value] call ULP_fnc_addMoney;
				[format["You have withdrawn <t color='#B92DE0'>%1%2</t>.", "£", [_value] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};
		};
	}, false
] call ULP_fnc_selectNumber;