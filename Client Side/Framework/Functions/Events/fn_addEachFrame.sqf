/*
** Author: Jack "Scarso" Farhall
** Description: 
** Credit: https://github.com/CBATeam/CBA_A3/blob/master/addons/common/fnc_addPerFrameHandler.sqf
*/
scopeName "fn_addEachFrame";

if (canSuspend) exitWith {
	[ULP_fnc_addEachFrame, _this] call ULP_fnc_directCall;
};

_this params [
	["_params", []],
	["_function", {}, [{}]],
	["_delay", 0, [0]]
];

if (_function isEqualTo {}) exitWith { -1 };

private _handle = ULP_eachFrameEventsHandles pushBack (count ULP_eachFrameEventsHandlers);
ULP_eachFrameEventsHandlers pushBack [_params, _function, _delay, diag_tickTime, _handle];

_handle