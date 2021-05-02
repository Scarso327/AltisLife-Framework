/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_revivePatient";

if (canSuspend) exitWith {
    [ULP_fnc_revivePatient, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

if (!([player, ["Medic"]] call ULP_fnc_isFaction) && { (count (["Medic"] call ULP_fnc_allMembers)) >= 0 }) exitWith {
	["You can't revive someone while medics are online..."] call ULP_fnc_hint;
};

private _unit = _display getVariable ["patient", objNull];

if !(isDowned(_unit)) exitWith {
	["This patient is stable and doesn't require bandaging..."] call ULP_fnc_hint;
};

if ((count (_unit getVariable ["IncapacitatedWounds", createHashMap])) > 0) exitWith {
	["This patient still has open wounds that must be closed..."] call ULP_fnc_hint;
};

if (["AutomatedExternalDefibrillator"] call ULP_fnc_hasItem < 1) exitWith {
	["You require an AED in order to revive this patient..."] call ULP_fnc_hint;
};

closeDialog 0;

private _time = ["LifeSaver", 20] call ULP_fnc_activatePerk;

[format ["Reviving %1", [_unit] call ULP_fnc_getName], _time, [_unit], { isDowned(_this select 0) && { (player distance (_this select 0)) < 5 } }, {
	_this params [ "_unit" ];

	if !(isDowned(_unit)) exitWith {
		["This patient is stable and doesn't require bandaging..."] call ULP_fnc_hint;
	};

	private _payOut = ["Revival", 5000] call ULP_fnc_getLegislation;

	if ([player, ["Medic"]] call ULP_fnc_isFaction && { [_payOut, true, format ["Reviving %1", [_unit] call ULP_fnc_getName]] call ULP_fnc_addMoney }) then {
		[format ["You have revived %1 and been paid %2%3", [_unit] call ULP_fnc_getName, "£", [_payOut] call ULP_fnc_numberText]] call ULP_fnc_hint;
	} else {
		[format ["You have revived %1", [_unit] call ULP_fnc_getName]] call ULP_fnc_hint;
	};

	[100, format ["Reviving %1", [_unit] call ULP_fnc_getName]] call ULP_fnc_addXP;
	[player] remoteExecCall ["ULP_fnc_revived", _unit];
}, {} , ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;