/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_SetAssignedMedic";

_this params [ "_button" ];

if (isNull _button) exitWith {};

private _display = ctrlParent _button;

private _list = _display displayCtrl 5402;

private _index = tvCurSel _list;
private _unit = (_list tvData _index) call BIS_fnc_objectFromNetId;

if (isNull _unit || { !(isDowned(_unit)) }) exitWith {};

if ((_display getVariable ["Cooldown", 0]) > time) exitWith {
	["Please wait before preforming this action again"] call ULP_fnc_hint;
};

if ([_unit] call ULP_fnc_setMedicalAssignment) then {
	_display setVariable ["Cooldown", time + 5];
};