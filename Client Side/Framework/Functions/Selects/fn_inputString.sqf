/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_inputString";

_this params [
	["_parent", displayNull, [displayNull]],
	["_boundaries", [0, 1], [[]]],
	["_params", [], [[]]],
	["_onSelect", {}, [{}]],
	["_tablet", true, [false]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplayInputText";

(_display displayCtrl 3701) ctrlShow _tablet;
(_display displayCtrl 3702) ctrlShow !_tablet;

private _input = _display displayCtrl 3705;
private _button = _display displayCtrl 3706;

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];