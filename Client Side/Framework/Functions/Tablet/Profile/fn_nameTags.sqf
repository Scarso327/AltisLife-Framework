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

private _iconList = _display displayCtrl 23069;
tvClear _iconList;

{
	private _cfg = _x;
	private _category = _iconList tvAdd [[], configName _cfg];

	{
		private _iconCfg = missionConfigFile >> "CfgTags" >> "Icons" >> _x;
		if (isClass _iconCfg && { call compile getText (_iconCfg >> "condition") }) then {
			private _path = getText (_iconCfg >> "icon");

			private _icon = _iconList tvAdd [[_category], getText (_iconCfg >> "displayName")];
			_iconList tvSetData [[_category, _icon], configName _iconCfg];
			_iconList tvSetPicture [[_category, _icon], _path];

			if (_path isEqualTo (player getVariable ["icon", ""])) then {
				_iconList tvSetCurSel [_category, _icon];
			};
		};
	} forEach (getArray (_cfg >> "icons"));
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgTags" >> "Categories"));

_iconList tvAdd [[], "Clear Icon"];

(profileNamespace getVariable["selected_name_colour", [player] call ULP_fnc_getTagColour]) params [ "_r", "_g", "_b" ];

{
	_x params [ "_ctrl", "_val" ];

	_ctrl sliderSetRange [0, 100];
	_ctrl sliderSetSpeed [1, 1, 1];
	_ctrl sliderSetPosition (round(_val * 100));
} forEach [
	[(_display displayCtrl 23072), _r],
	[(_display displayCtrl 23073), _g],
	[(_display displayCtrl 23074), _b]
];

_display setVariable ["color_selected", [_r,_g,_b,1]];

[_display] call ULP_fnc_updateTagPreview;