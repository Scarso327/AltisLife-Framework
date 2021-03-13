/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\..\UI\gridCommon.inc"
scopeName "fn_achievements";

_display = _this;
if (isNull _display) exitWith {};

private _ctrls = _display getVariable ["display_ctrls", []];

if !(_ctrls isEqualTo []) then {
	{ ctrlDelete _x; } forEach _ctrls;
};

_ctrls = [];

private _achievements = ("isClass _x" configClasses (missionConfigFile >> "CfgProgression" >> "CfgAchievements")) apply {
	[(switch (true) do {
		case ([configName _x] call ULP_fnc_hasAchieved) : { 0 };
		case (getNumber (_x >> "isMystery") isEqualTo 1) : { 2 };
		default { 1 };
	}), _x]
};

_achievements sort true;

private _ctrlGroup = _display displayCtrl 23030;
private _achieveCtrl = controlNull;
private _lastCtrlPos = [];
private _xInc = false;
private _item = 1;

{
	_x params ["_state", "_cfg"];

	_achieveCtrl = _display ctrlCreate ["ULP_ctrlAchievement", -1, _ctrlGroup];

	if !(_lastCtrlPos isEqualTo []) then {
		_lastCtrlPos params ["_xAxis", "_yAxis", "_w", "_h"];

		_achieveCtrl ctrlSetPositionY _yAxis;

		if ((_item % 5) isEqualTo 0) then {
			_achieveCtrl ctrlSetPositionY ((_yAxis + ((1 * GUI_GRID_CENTER_H) / 2)) + _h);
			_achieveCtrl ctrlSetPositionX ((1 * GUI_GRID_CENTER_W) / 2);
		} else {
			_achieveCtrl ctrlSetPositionX ((_xAxis + ((1 * GUI_GRID_CENTER_W) / 2)) + _w);
			_xInc = false;
		};

		_item = _item + 1;
	};

	_achieveCtrl ctrlCommit 0;

	private _iconCtrl = _achieveCtrl controlsGroupCtrl 101;
	_iconCtrl ctrlSetText getText (_cfg >> "icon");
	_iconCtrl ctrlSetTooltip getText (_cfg >> "description");

	private _nameCtrl = _achieveCtrl controlsGroupCtrl 102;
	_nameCtrl ctrlSetStructuredText parseText format["<t align='center'>%1</t>", 
		[
			getText (_cfg >> "displayName"),
			"??????"
		] select (_state isEqualTo 2)
	];
	_nameCtrl ctrlSetTooltip (["Unlocked", "Locked"] select (_state isEqualTo 1));
	_nameCtrl ctrlEnable false;

	private _coverCtrl = _achieveCtrl controlsGroupCtrl 103;
	_coverCtrl ctrlShow !(_state isEqualTo 0);
	_coverCtrl ctrlSetTooltip (["Locked", "Mystery Achievemnt"] select (_state isEqualTo 2));

	if (_state isEqualTo 0 && { getNumber (_cfg >> "isMystery") isEqualTo 1 }) then {
		_iconCtrl ctrlSetTextColor [1, 0.843, 0, 1];
		_nameCtrl ctrlSetTextColor [1, 0.843, 0, 1];
	};

	_lastCtrlPos = ctrlPosition _achieveCtrl;
	_ctrls pushBack _achieveCtrl;
} forEach _achievements;

_display setVariable ["display_ctrls", _ctrls];