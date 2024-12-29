/*
** Author: Jack "Scarso" Farhall
** Description: Basically just an eachFrame handler like arma's onEachFrame event but this allows everything to be put into one handler.
*/
scopeName "fn_addEachFrame";

// See https://github.com/CBATeam/CBA_A3/wiki/Per-Frame-Handlers

if (canSuspend) exitWith {
	[ULP_fnc_addEachFrame, _this] call ULP_fnc_directCall;
};

_this params [
	["_params", []],
	["_function", {}, [{}]]
];

if (_function isEqualTo {}) exitWith { -1 };

private _index = ULP_eachFrameEventsHandles pushBack (count ULP_eachFrameEventsHandlers);
ULP_eachFrameEventsHandlers pushBack [_params, _function, _index];

_index