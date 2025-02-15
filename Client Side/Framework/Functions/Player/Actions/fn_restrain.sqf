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
if (isNull _target || { !(isPlayer _target) } || { !(isNull _detainer) && { !([_detainer] call ULP_fnc_onDuty) } && { (_target distance _detainer) > 5 } }) exitWith { false };

if ([player, ["Police"]] call ULP_fnc_isFaction || { ["cuffCourier"] call ULP_fnc_hasPerk } || { [_detainer] call ULP_fnc_onDuty } || { ["Ziptie", 1, _restrain] call ULP_fnc_handleItem }) exitWith {
	_this remoteExecCall ["ULP_fnc_setRestrainedState", _target];
	["Retain"] call ULP_fnc_achieve;
	
	true
};

["You need a ziptie to restrain someone"] call ULP_fnc_hint;
false