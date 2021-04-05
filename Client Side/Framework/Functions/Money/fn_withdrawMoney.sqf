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

private _amount = ([BANK, [] call ULP_fnc_groupFunds] select (_group));
if (_amount <= 0) exitWith {
	hint "You don't have anything to withdraw...";
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
			hint format ["Attempting to withdraw %1%2...", "£", [_value] call ULP_fnc_numberText];
			[player, _value] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
		} else {
			if (_value > BANK) exitWith {
				hint format["You don't have %1%2 to withdraw...", "£", [_value] call ULP_fnc_numberText];
			};

			if ([_value, true, "Bank Withdrawal"] call ULP_fnc_removeMoney) then {
				[_value] call ULP_fnc_addMoney;
				hint format["You have withdrawn %1%2", "£", [_value] call ULP_fnc_numberText];
			};
		};
	}, false
] call ULP_fnc_selectNumber;