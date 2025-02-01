/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscProgress_OnEachFrame";
disableSerialization;

_this params [
	"_display", "_ctrlProgress", "_ctrlProgressText"
];

if (isNull _display) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

private _startTime = _display getVariable ["start", time];
private _endTime = _display getVariable ["end", _startTime + 5];
private _params = _display getVariable ["params", []];
private _condition = _display getVariable ["condition", { true }];
private _eachframe = _display getVariable ["eachframe", {}];
private _anim = _display getVariable ["anim", ""];

if (!(_params call _condition) || { !alive player } || { isDowned(player) }) exitWith {
	[_display, false] call ULP_UI_fnc_endProgress;
};

private _progress = ((time - _startTime) / (_endTime - _startTime)) * 100;

_progress call _eachframe;

_ctrlProgress progressSetPosition _progress / 100;
_ctrlProgressText ctrlSetText format["%1%2", floor _progress, "%"];

if (_progress >= 100) exitWith {
	[_display, true] call ULP_UI_fnc_endProgress;
};

if !(_anim isEqualTo "") then { player playMoveNow _anim };