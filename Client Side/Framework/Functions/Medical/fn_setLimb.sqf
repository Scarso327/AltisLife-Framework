/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setLimb";

if (canSuspend) exitWith {
    [ULP_fnc_setLimb, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]],
	["_limb", "", [""]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _unit = _display getVariable ["patient", objNull];
private _wounds = + (_unit getVariable ["IncapacitatedWounds", createHashMap]);

private _limbWounds = _wounds getOrDefault [_limb, createHashMap];

private _list = _display displayCtrl 4909;
lnbClear _list;

{
	private _row = _list lnbAddRow [_x, [_y] call ULP_fnc_numberText];
	_list lnbSetData [[_row, 0], _x];
	_list lnbSetValue [[_row, 1], _y];
} forEach _limbWounds;

(_display displayCtrl 4907) ctrlSetText format ["%1's Status", _limb];
_display setVariable ["limb", _limb];