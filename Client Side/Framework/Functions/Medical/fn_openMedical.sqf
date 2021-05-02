/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openMedical";

if (canSuspend) exitWith {
    [ULP_fnc_openMedical, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", objNull, [objNull]]
];

if ([player] call ULP_fnc_isRestrained || { [player] call ULP_fnc_isSurrendered } || { isDowned(player) } || { !(isDowned(_unit)) }) exitWith {};

if (createDialog "DialogMedical") then {
	private _display = findDisplay 4900;

	[(_display displayCtrl 4908), (_display displayCtrl 4909), [0, 1]] call BIS_fnc_initListNBoxSorting;

	_display setVariable ["patient", _unit];
	[(_display displayCtrl 4901), "Head"] call ULP_fnc_setLimb;
};