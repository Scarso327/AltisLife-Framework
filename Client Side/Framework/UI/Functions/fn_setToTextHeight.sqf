/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setToTextHeight";

_this params [
	["_control", controlNull, [controlNull]],
	["_commit", true, [false]]
];

if (isNull _control) exitWith {};

(ctrlPosition _control) params ["_xAxis", "_yAxis", "_w", "_h"];

private _defaultHeight = _control getVariable ["ULP_UI_DefaultHeight", -1];

if (_defaultHeight isEqualTo -1) then {
	_defaultHeight = _h;
	_control setVariable ["ULP_UI_DefaultHeight", _defaultHeight];
};

private _textHeight = ctrlTextHeight _control;

_control ctrlSetPosition [_xAxis, _yAxis, _w, [
	_defaultHeight,
	_textHeight
] select (_textHeight > _defaultHeight)];

if (_commit) then {
	_control ctrlCommit 0;
};