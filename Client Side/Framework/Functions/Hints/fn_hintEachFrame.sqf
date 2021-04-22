/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_hintEachFrame";

if (canSuspend) exitWith {
    [ULP_fnc_hintEachFrame, _this] call ULP_fnc_directCall;
};

private _display = _this;
if (isNull _display) exitWith {
	[_thisEventHandler] call ULP_fnc_removeEachFrame;
};

private _hints = + (_display getVariable ["hints", []]);

{
	private _hint = _x;

	if (diag_tickTime > (_hint getVariable ["duraction", 0])) then {
		(ctrlPosition _hint) params ["", "_y", "", "_h"];

		_hint ctrlSetPositionY (_y + _h);
		_hint ctrlSetFade 1;
		_hint ctrlCommit 0.25;

		_hints deleteAt (_hints find _hint);

		[{ ctrlCommitted _this }, _hint, { ctrlDelete _this; }] call ULP_fnc_waitUntilExecute;
	};
} forEach _hints;

_display setVariable ["hints", _hints];