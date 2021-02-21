/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_eachFrameProgress";

_this params [
	"_ui", "_ctrlProgress", "_ctrlProgressText"
];

if (isNull _ui) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

private _startTime = _ui getVariable ["start", time];
private _endTime = _ui getVariable ["end", _startTime + 5];
private _params = _ui getVariable ["params", []];
private _condition = _ui getVariable ["condition", { true }];
private _anim = _ui getVariable ["anim", ""];

if !(_params call _condition) exitWith {
	[_ui, false] call ULP_UI_endProgress;
};

private _progress = ((time - _startTime) / (_endTime - _startTime)) * 100;

_ctrlProgress progressSetPosition _progress / 100;
_ctrlProgressText ctrlSetText format["%1%2", floor _progress, "%"];

if (_progress >= 100) exitWith {
	[_ui, true] call ULP_UI_fnc_endProgress;
};

if !(_anim isEqualTo "") then { player playMoveNow _anim };