/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_restrain";

if (canSuspend) exitWith {
    [ULP_fnc_restrain, _this] call ULP_fnc_directCall;
};

_this params [
	["_target", cursorObject, [objNull]],
	["_detainer", objNull, [objNull]],
	["_restrain", false, [true]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) } || { (_target distance _detainer) > 5 }) exitWith {};

if !(local _target) exitWith {
    _this remoteExecCall ["ULP_fnc_restrain", _target];
};

if (_restrain) then {
	if ([_target] call ULP_fnc_isRestrained) exitWith {}; // Already restrained...
	_target setVariable ["restrained", _detainer, true];
	
	[] spawn ULP_UI_fnc_closeDialogs;

	if ([_target] call ULP_fnc_isSurrendered) then { _target setVariable ["surrender", nil, true]; };
	if !((currentWeapon _target) isEqualTo "") then { _target action ["SwitchWeapon", _target, _target, 100]; };
	if ([] call ULP_fnc_isEscorting) then { detach ULP_Escort; ULP_Escort = nil; };

	if !(isNil "ULP_RestrainEVH") then { [ULP_RestrainEVH] call ULP_fnc_removeEachFrame; };

	ULP_RestrainEVH = [_target, {
		if !(alive _this || { [_this] call ULP_fnc_isRestrained }) exitWith {
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
			[_this] call ULP_fnc_restrain;
		};

		if (isNull (objectParent _this) && { !([_this] call ULP_fnc_isKnocked) } && { !(isDowned(_this)) }) then {
			_this playMoveNow "AmovPercMstpSnonWnonDnon_Ease";
		};
    }] call ULP_fnc_addEachFrame;

	hint format ["You've been restrained by %1", name _detainer];
} else {
	if !([_target] call ULP_fnc_isRestrained) exitWith {}; // Already restrained...
	if !(isNil "ULP_RestrainEVH") then { [ULP_RestrainEVH] call ULP_fnc_removeEachFrame; };
	_target setVariable ["restrained", nil, true];

	if (alive _target && { !(isDowned(_target)) }) then {
		_target playMove (["IDLE", "STAND"] call ULP_fnc_getAnim);
	};

	if ([_target] call ULP_fnc_isEscorted) then {
		detach _target;
	};
	
	hint format ["You've been unrestrained by %1", name _detainer];
};