/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_updateTagPreview";

_this params [
	["_display", displayNull, [displayNull]],
	["_name", [player] call ULP_fnc_getName, [""]],
	["_subtitle", player getVariable ["subtitle", ""], [""]],
	["_title", player getVariable ["title", ""], [""]]
];

if (isNull _display) exitWith {};

private _nameCtrl = _display displayCtrl 23054;
private _subtitleCtrl = _display displayCtrl 23055;
private _titleCtrl = _display displayCtrl 23058;

_nameCtrl ctrlSetStructuredText parseText format["<t align='center' color='#00E613'>%1</t>", _name];
_subtitleCtrl ctrlSetStructuredText parseText format["<t align='center'>%1</t>", _subtitle];
_titleCtrl ctrlSetStructuredText parseText format["<t align='center'>%1</t>", _title];