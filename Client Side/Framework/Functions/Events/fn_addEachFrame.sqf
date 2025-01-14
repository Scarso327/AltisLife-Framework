/*
** Author: Jack "Scarso" Farhall
** Description: 
** Credit: https://github.com/CBATeam/CBA_A3/blob/master/addons/common/fnc_addPerFrameHandler.sqf
*/
scopeName "fn_addEachFrame";

_this params [
	["_params", []],
	["_function", {}, [{}]]
];

if (_function isEqualTo {}) exitWith { -1 };

private _handle = ULP_eachFrameEventsHandles pushBack (count ULP_eachFrameEventsHandlers);
ULP_eachFrameEventsHandlers pushBack [_params, _function, _handle];

_handle