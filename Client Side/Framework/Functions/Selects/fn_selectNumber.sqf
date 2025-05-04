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
	["_tablet", true, [false]],
	["_format", "[_this select 1] call ULP_fnc_numberText", [""]],
	["_allowManual", true, [false]]
];

if (isNull _parent) exitWith {};

private _min = _boundaries select 0;
private _max = _boundaries select 1;

if (_min isEqualTo _max) exitWith {
	_params append [displayNull, _max];
	_params call _onSelect;
};

private _display = _parent createDisplay "DisplaySelectNumber";
_display setVariable ["format", _format];

(_display displayCtrl 3207) ctrlShow _tablet;
(_display displayCtrl 3208) ctrlShow !_tablet;

private _minMaxText = _display displayCtrl 3204;
private _slider = _display displayCtrl 3205;
private _button = _display displayCtrl 3206;
private _input = _display displayCtrl 3209;
_input ctrlEnable _allowManual;

_slider sliderSetRange _boundaries;
_slider sliderSetPosition 1;
_slider sliderSetSpeed [1, 1, 1];

_minMaxText ctrlSetStructuredText parseText format["<t align='left'>%1</t><t align='right'>%2</t>",
	[_boundaries select 0] call ULP_fnc_numberText,
	[_boundaries select 1] call ULP_fnc_numberText
];

_input ctrlSetText ([_boundaries select 0] call ULP_fnc_numberText);

_input ctrlAddEventHandler ["KeyUp", {
	_this params [ "_ctrl" ];

	private _display = ctrlParent _ctrl;
	private _slider = _display displayCtrl 3205;

	(sliderRange _slider) params ["_min", "_max"];
	_slider sliderSetPosition (_max min ((parseNumber ctrlText _ctrl) max _min));
}];

_slider ctrlAddEventHandler ["SliderPosChanged", {
	_this params [ "_ctrl", "_val" ];

	private _display = ctrlParent _ctrl;
	private _input = _display displayCtrl 3209;
	_input ctrlSetText ([_display, _val] call compile (_display getVariable ["format", "[_this select 1] call ULP_fnc_numberText"]));
}];

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];