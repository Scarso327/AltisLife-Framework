/*
** Author: Jack "Scarso" Farhall
** Description: https://community.bistudio.com/wiki/ctrlSetStructuredText Example 3, Fix VAlign
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setVAlignText";

_this params [
	["_ctrl", controlNull, [controlNull]],
	["_text", "", [""]],
	["_horizontal", "center", [""]]
];

if (isNull _ctrl) exitWith { false };

private _lineHeight = getNumber (configFile >> "RscStructuredText" >> "size");
private _linesTotal = (ctrlPosition _ctrl select 2) / _lineHeight;
private _trailingSpace = "";
for "_i" from 1 to _linesTotal do { _trailingSpace = _trailingSpace + " " };

_ctrl ctrlSetStructuredText parseText format ["<t size='%1'><t size='1' align='%4' valign='middle'>%2%3</t> </t>", _linesTotal, _text, _trailingSpace, _horizontal];

true