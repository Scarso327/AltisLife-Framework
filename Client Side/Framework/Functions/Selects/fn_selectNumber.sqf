/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_selectNumber";

_this params [
	["_parent", displayNull, [displayNull]],
	["_boundaries", [0, 1], [[]]],
	["_params", [], [[]]],
	["_onSelect", {}, [{}]],
	["_tablet", true, [false]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplaySelectNumber";

(_display displayCtrl 3207) ctrlShow _tablet;
(_display displayCtrl 3208) ctrlShow !_tablet;

private _minMaxText = _display displayCtrl 3204;
private _slider = _display displayCtrl 3205;
private _button = _display displayCtrl 3206;

_slider sliderSetRange _boundaries;
_slider sliderSetPosition 1;
_slider sliderSetSpeed [1, 1, 1];

_minMaxText ctrlSetStructuredText parseText format["<t align='left'>%1</t><t align='right'>%2</t>",
	_boundaries select 0,
	_boundaries select 1
];

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];