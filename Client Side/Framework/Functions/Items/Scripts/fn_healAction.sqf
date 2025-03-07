/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_healAction";

private _target = _this;
if (isNull _target || { !([_target] call ULP_fnc_canHeal) }) exitWith { false };

private _hasMedkit = ((["MediKit"] call ULP_fnc_hasItem) > 0);

private _time = 15;
if (_hasMedkit) then { _time = 8; };

if !([format["Healing %1", name _target], _time, [_target, _hasMedkit], { [(_this select 0)] call ULP_fnc_canHeal }, {
	_this params [ "_target", "_hasMedkit" ];

	if !([_target] call ULP_fnc_canHeal) exitWith {};

	if !(_hasMedkit) then { ["FirstAidKit", 1, true] call ULP_fnc_handleItem; };

	private _newDamage = ([["FirstAider", 0.25] call ULP_fnc_activatePerk, 0] select (_hasMedkit));
	private _currentDamage = damage _target;

	if (_newDamage < _currentDamage) then {
		_target setDamage _newDamage;
	};

	[format ["You've healed <t color='#B92DE0'>%1</t>!", name _target]] call ULP_fnc_hint;

	private _payOut = ["Revival", 5000] call ULP_fnc_getLegislation;

	if ([player, ["Medic"]] call ULP_fnc_isFaction 
		&& { _target getVariable ["Wounded", false] } 
		&& { [_payOut, true, format ["Healing %1", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_addMoney }) then {
		[format ["You have been paid <t color='#B92DE0'>%1%2</t> for healing a wounded person", "£", [_payOut] call ULP_fnc_numberText]] call ULP_fnc_hint;
	};

	["Healed", [player]] remoteExecCall ["ULP_fnc_invokeEvent", _target];
}, {}, ["GRAB", (["PRONE", "CROUCH"] select ((stance player) isEqualTo "STAND"))]] call ULP_UI_fnc_startProgress) exitWith {
	["You can't heal while doing something else..."] call ULP_fnc_hint;
	false
};

true