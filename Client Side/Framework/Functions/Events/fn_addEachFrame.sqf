/*
** Author: Jack "Scarso" Farhall
** Description: Basically just an eachFrame handler like arma's onEachFrame event but this allows everything to be put into one handler.
*/
scopeName "fn_addEachFrame";

if (canSuspend) exitWith {
	[ULP_fnc_addEachFrame, _this] call ULP_fnc_directCall;
};

_this params [
	["_params", []],
	["_function", {}, [{}]]
];

if (_function isEqualTo {}) exitWith { -1 };

private _index = ULP_eachFrameEvents getOrDefault ["#lastId", -1];
_index = _index + 1;

ULP_eachFrameEvents set [_index, _this];
ULP_eachFrameEvents set ["#lastId", _index];

_index