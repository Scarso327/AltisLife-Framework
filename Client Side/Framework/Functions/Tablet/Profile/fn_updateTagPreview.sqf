/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_updateTagPreview";

_this params [
	["_display", displayNull, [displayNull]],
	["_icon", profileNamespace getVariable ["selected_icon", "."], [""]],
	["_name", [player] call ULP_fnc_getName, [""]],
	["_subtitle", player getVariable ["subtitle", ""], [""]],
	["_title", player getVariable ["title", ""], [""]],
	["_colour", (([player] call ULP_fnc_getTagColour) call BIS_fnc_colorRGBAtoHTML), [""]]
];

if (isNull _display) exitWith {};

private _iconCtrl = _display displayCtrl 23053;
private _nameCtrl = _display displayCtrl 23054;
private _subtitleCtrl = _display displayCtrl 23055;
private _titleCtrl = _display displayCtrl 23058;

if !(_icon isEqualTo ".") then { _iconCtrl ctrlSetText getText(missionConfigFile >> "CfgTags" >> "Icons" >> _icon >> "icon"); };
if !(_name isEqualTo "") then { _nameCtrl ctrlSetStructuredText parseText format["<t align='center' color='%2'>%1</t>", _name, _colour]; };
if !(_subtitle isEqualTo "") then { _subtitleCtrl ctrlSetStructuredText parseText format["<t align='center'>%1</t>", _subtitle]; };
if !(_title isEqualTo "") then { _titleCtrl ctrlSetStructuredText parseText format["<t align='center'>%1</t>", _title]; };