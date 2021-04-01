/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_nameTags";

_display = _this;
if (isNull _display) exitWith {};

private _titleDropdown = _display displayCtrl 23056;
lbClear _titleDropdown;

private _titles = ["Default"];
_titles append ULP_Titles;
private _selected = 0;

{
	private _class = missionConfigFile >> "CfgTitles" >> _x;

	if (isClass _class) then {
		private _title = _titleDropdown lbAdd getText (_class >> "displayName");
		_titleDropdown lbSetData [_title, ([
			configName _class, 
			getText (_class >> "varOverride")
		] select (isText (_class >> "varOverride")))];

		private _tooltip = getText (_class >> "description");
		if !(_tooltip isEqualTo "") then {
			_titleDropdown lbSetTooltip [_title, _tooltip];
		};
		
		if ((profileNamespace getVariable ["selected_title", ""]) isEqualTo _x) then {
			_selected = _title;
		};
	};
} forEach _titles;

_titleDropdown lbSetCurSel _selected;

[_display] call ULP_fnc_updateTagPreview;