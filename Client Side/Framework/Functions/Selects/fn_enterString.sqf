/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_enterString";

_this params [
	["_parent", displayNull, [displayNull]],
	["_title", "Enter Text", [""]],
	["_buttons", ["Enter", "Cancel"], [[]]],
	["_placeholderText", "", [""]],
	["_params", [], [[]]],
	["_onEnter", {}, [{}]],
	["_tablet", true, [false]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplayInput";

(_display displayCtrl 4405) ctrlShow _tablet;
(_display displayCtrl 4406) ctrlShow !_tablet;

(_display displayCtrl 4401) ctrlSetText _title;

private _input = _display displayCtrl 4402;
private _placeholder = _display displayCtrl 4407;
_input ctrlSetStructuredText parseText _message;

[_input, _placeholder] call ULP_UI_fnc_placeholder;

(_display displayCtrl 4404) ctrlSetStructuredText parseText format ["<t align = 'center'>%1</t>", _buttons select 0];
(_display displayCtrl 4403) ctrlSetStructuredText parseText format ["<t align = 'center'>%1</t>", _buttons select 1];

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onEnter];