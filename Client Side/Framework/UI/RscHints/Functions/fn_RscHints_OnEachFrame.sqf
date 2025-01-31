/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscHints_OnEachFrame";
disableSerialization;

_this params [ "_display" ];

if (isNull _display) exitWith {};

private _hints = + (_display getVariable ["hints", []]);

{
	private _hint = _x;

	if (diag_tickTime > (_hint getVariable ["duraction", 0]) || { (count _hints) >= 15 && { _forEachIndex >= 15 } }) then {
		(ctrlPosition _hint) params ["", "_y", "", "_h"];

		_hint ctrlSetPositionY (_y + _h);
		_hint ctrlSetFade 1;
		_hint ctrlCommit 0.25;

		_hints deleteAt (_hints find _hint);

		[{ ctrlCommitted _this }, _hint, { ctrlDelete _this; }] call ULP_fnc_waitUntilExecute;
	};
} forEach _hints;

_display setVariable ["hints", _hints];