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

private _unit = _display getVariable ["patient", objNull];
if (isNull _unit) exitWith {};

private _isNotMedic = (!([player, ["Medic"]] call ULP_fnc_isFaction) && { !(([["Medic"]] call ULP_fnc_onlineFaction) isEqualTo 0) });

if (_isNotMedic && { !(isNull (_unit getVariable ["AssignedMedic", objNull])) }) exitWith {
	["There is a medic assigned to this person..."] call ULP_fnc_hint;
};

private _civilianBleedOutRemainingAllowRevivalThreshold = getNumber (missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "CivilianBleedOutRemainingAllowRevival");
private _bleedOutEndTime = (_unit getVariable ["IncapacitatedBleedOutTime", serverTime + 10]);

if (_isNotMedic && { (_bleedOutEndTime - serverTime) > _civilianBleedOutRemainingAllowRevivalThreshold }) exitWith {
	[format ["There are medics online so you can only revive this person in %1...", [(_bleedOutEndTime - _civilianBleedOutRemainingAllowRevivalThreshold) - serverTime, "MM:SS"] call BIS_fnc_secondsToString]] call ULP_fnc_hint;
};

if !(isDowned(_unit)) exitWith {
	["This patient isn't incapacitated..."] call ULP_fnc_hint;
};

if !((count (_unit getVariable ["IncapacitatedWounds", createHashMap])) isEqualTo 0) exitWith {
	["This patient still has open wounds that must be closed..."] call ULP_fnc_hint;
};

if (["Defibrillator"] call ULP_fnc_hasItem < 1) exitWith {
	["You require an defibrillator in order to revive this patient..."] call ULP_fnc_hint;
};

closeDialog 0;

private _time = ["LifeSaver", 10] call ULP_fnc_activatePerk;

private _profCal = ["Reviving"] call ULP_fnc_getProfessionCalculation;
if (_profCal > 0) then { _time = _time - (_time * (_profCal / 100)); };

[format ["Reviving %1", [_unit, true] call ULP_fnc_getName], _time, [_unit], { isDowned(_this select 0) && { 
	(player distance (_this select 0)) < 5 && { [player, ["Medic"]] call ULP_fnc_isFaction || { isNull ((_this select 0) getVariable ["AssignedMedic", objNull]) } }
} }, {
	_this params [ "_unit" ];

	if !(isDowned(_unit)) exitWith {
		["This patient is stable and doesn't require bandaging..."] call ULP_fnc_hint;
	};

	private _payOut = ["Revival", 5000] call ULP_fnc_getLegislation;

	if ([player, ["Medic"]] call ULP_fnc_isFaction && { [_payOut, true, format ["Reviving %1", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_addMoney }) then {
		_unit setVariable ["Wounded", nil, true];
		[format ["You have revived <t color='#B92DE0'>%1</t> and been paid <t color='#B92DE0'>%2%3</t>", [_unit] call ULP_fnc_getName, "£", [_payOut] call ULP_fnc_numberText]] call ULP_fnc_hint;
	} else {
		[format ["You have revived <t color='#B92DE0'>%1</t>", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;
	};

	["LifeSaver"] call ULP_fnc_achieve;

	["Reviving", 1, 75] call ULP_fnc_increaseProfession;
	[150, format ["Reviving %1", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_addXP;

	["RevivedSomeone", [_unit]] call ULP_fnc_invokeEvent;

	[player] remoteExecCall ["ULP_fnc_revived", _unit];
	[getPlayerUID player, "Revive", [getPlayerUID _unit]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
}, {
	_this params [ "_unit" ];

	if !(isNull (_unit getVariable ["AssignedMedic", objNull])) then {
		["A medic has assigned themselves to this patient"] call ULP_fnc_hint;
	};
} , ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;