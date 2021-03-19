/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_depositMoney";

if (canSuspend) exitWith {
    [ULP_fnc_depositMoney, _this] call ULP_fnc_directCall;
};

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _group = _display getVariable ["group", false];

private _amount = CASH;
if (_amount <= 0) exitWith {
	hint "You don't have anything to deposit...";
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [1, _amount], [_group],
	{
		_this params [
			["_group", false, [true]],
			["_display", displayNull, [displayNull]],
			["_value", 1, [0]]
		];

		if (_value > CASH) exitWith {
			hint format["You don't have %1%2 to deposit...", "£", [_value] call ULP_fnc_numberText];
		};

		if ([_value, false] call ULP_fnc_removeMoney) then {
			[_value, true, "Bank Deposit"] call ULP_fnc_addMoney;
			hint format["You have deposited %1%2", "£", [_value] call ULP_fnc_numberText];
		};
	}, false
] call ULP_fnc_selectNumber;