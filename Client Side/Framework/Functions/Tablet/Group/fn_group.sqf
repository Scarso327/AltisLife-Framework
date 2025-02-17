/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_group";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

_display setVariable ["group_check", ([[_display], {
	_this params [
		["_display", displayNull, [displayNull]]
	];

	if (isNull _display || { !([] call ULP_fnc_isGroup) }) exitWith {
		if !(isNull _display) then {
			_display setVariable ["group_check", nil];
			["Home"] call ULP_fnc_setScreen;
		};
		[_thisEventHandler] call ULP_fnc_removeEachFrame;
	};
}] call ULP_fnc_addEachFrame)];

private _toolbox = _display displayCtrl 23061;

switch (lbCurSel _toolbox) do {
	case 3: { ["GroupSettings"] call ULP_fnc_setScreen; };
	case 2: { ["GroupAlliances"] call ULP_fnc_setScreen; };
	case 1: { ["GroupProgression"] call ULP_fnc_setScreen; };
	default { ["GroupOverview"] call ULP_fnc_setScreen; };
};