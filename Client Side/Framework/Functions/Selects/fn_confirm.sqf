/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_confirm";

_this params [
	["_parent", displayNull, [displayNull]],
	["_title", "Confirmation", [""]],
	["_buttons", ["Yes", "No"], [[]]],
	["_message", "Yes or no?", [""]],
	["_params", [], [[]]],
	["_onYes", {}, [{}]],
	["_tablet", true, [false]],
	["_onNo", {}, [{}]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplayConfirm";

(_display displayCtrl 4305) ctrlShow _tablet;
(_display displayCtrl 4306) ctrlShow !_tablet;

(_display displayCtrl 4301) ctrlSetText _title;
(_display displayCtrl 4302) ctrlSetStructuredText parseText _message;

(_display displayCtrl 4304) ctrlSetStructuredText parseText format ["<t align = 'center'>%1</t>", _buttons select 0];
(_display displayCtrl 4303) ctrlSetStructuredText parseText format ["<t align = 'center'>%1</t>", _buttons select 1];

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onYes];
_display setVariable ["onNo", _onNo];