/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\..\UI\gridCommon.inc"
scopeName "fn_professions";

_display = _this;
if (isNull _display) exitWith {};

private _ctrls = _display getVariable ["profession_ctrls", []];

if !(_ctrls isEqualTo []) then {
	{ ctrlDelete _x; } forEach _ctrls;
};

private _faction = [player] call ULP_fnc_getFaction;

private _ctrlGroup = _display displayCtrl 23030;
private _professionCtrl = controlNull;
private _lastCtrlPos = [];
private _yInc = false;

{
	_professionCtrl = _display ctrlCreate ["ULP_ctrlProfession", -1, _ctrlGroup];

	if !(_lastCtrlPos isEqualTo []) then {
		_lastCtrlPos params ["_xAxis", "_yAxis", "_w", "_h"];

		_professionCtrl ctrlSetPositionY _yAxis;

		// Every second profession is shifted to the right...
		if (((_forEachIndex + 1) % 2) isEqualTo 0) then {
			_professionCtrl ctrlSetPositionX ((_xAxis + ((1 * GUI_GRID_CENTER_W) / 2)) + _w);
			_yInc = true; // If we shift, next will be on a new line...
		} else {
			if (_yInc) then {
				_professionCtrl ctrlSetPositionY ((_yAxis + ((1 * GUI_GRID_CENTER_H) / 2)) + _h);
				_yInc = false;
			};
		};
	};

	_professionCtrl ctrlCommit 0;

	([configName _x] call ULP_fnc_getProfessionLevel) params [
		"_level", "_points"
	];

	private _maxLevel = getNumber (_x >> "maxLevel");
	private _requirement = getNumber (_x >> "xpLevel");
	if (_level > 0) then {
		_requirement = _requirement * (getNumber (_x >> "xpMultipler") * _level);
	};

	private _iconCtrl = _professionCtrl controlsGroupCtrl 101;
	_iconCtrl ctrlSetText getText (_x >> "icon");
	_iconCtrl ctrlSetTooltip format["%1/%2", _points, _requirement];

	if (_level isEqualTo _maxLevel && { _points isEqualTo _requirement }) then {
		_iconCtrl ctrlSetTextColor [1, 0.843, 0, 1];
	};

	private _nameCtrl = _professionCtrl controlsGroupCtrl 102;
	_nameCtrl ctrlSetStructuredText parseText format["%1<t align='right'>%2/%3</t>", getText (_x >> "displayName"), _level, _maxLevel];

	private _descCtrl = _professionCtrl controlsGroupCtrl 103;
	_descCtrl ctrlSetStructuredText parseText format[getText (_x >> "effectDescription"), ([_level, _points] call compile getText (_x >> "effectCalculation")), "%"];

	private _progressCtrl = _professionCtrl controlsGroupCtrl 104;
	_progressCtrl progressSetPosition (_points / _requirement);

	_lastCtrlPos = ctrlPosition _professionCtrl;
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgProgression" >> "CfgProfessions"));