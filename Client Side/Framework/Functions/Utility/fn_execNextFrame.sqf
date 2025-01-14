/*
** Author: Jack "Scarso" Farhall
** Description: 
** Credit: https://github.com/CBATeam/CBA_A3/blob/master/addons/common/fnc_execNextFrame.sqf
*/
scopeName "fn_execNextFrame";

_this params [
	["_params", []],
	["_function", {}, [{}]]
];

if (diag_frameNo != ULP_nextFrameNumber) then {
	ULP_executeNextFrameBufferA pushBack [_params, _function];
} else {
	ULP_executeNextFrameBufferB pushBack [_params, _function];
};

nil