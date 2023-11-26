/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\..\UI\gridCommon.inc"
scopeName "fn_personalGoals";

_display = _this;
if (isNull _display) exitWith {};

private _ctrls = _display getVariable ["display_ctrls", []];

if !(_ctrls isEqualTo []) then {
	{ ctrlDelete _x; } forEach _ctrls;
};

_ctrls = [];

private _ctrlGroup = _display displayCtrl 23030;
private _lastCtrlPos = ctrlPosition controlNull;

{
	private _type = _x;
	private _goalHeader = _display ctrlCreate ["ULP_ctrlGoalsHeader", -1, _ctrlGroup];

	if !(_lastCtrlPos isEqualTo []) then {
		_goalHeader ctrlSetPositionY (((_lastCtrlPos # 1) + ((1 * GUI_GRID_CENTER_H) / 2)) + (_lastCtrlPos # 3));
	};

	_goalHeader ctrlCommit 0;

	_goalHeader ctrlSetText format["%1 Goals", _type];
	_lastCtrlPos = ctrlPosition _goalHeader;

	private _goals = missionNamespace getVariable [format["ULP_Goals_%1", _type], []];
	private _rawGoals = [];

	{ _rawGoals append _y; } forEach _goals; // We don't need their "types"
	
	{
		_x params [ "_cfgName", "_progress" ];
		
		private _goalCfg = missionConfigFile >> "CfgGoals" >> "Personal" >> _type >> _cfgName;
		if (isClass _goalCfg) then {
			private _tiers = getArray (_goalCfg >> "tiers");
			private _goal = _display ctrlCreate ["ULP_ctrlGoal", -1, _ctrlGroup];

			if !(_lastCtrlPos isEqualTo []) then {
				_goal ctrlSetPositionY (((_lastCtrlPos # 1) + ((1 * GUI_GRID_CENTER_H) / 2)) + (_lastCtrlPos # 3));
			};

			private _icon = "";
			private _item = getText (_goalCfg >> "item");
			
			if (isText (_goalCfg >> "icon")) then {
				_icon = getText (_goalCfg >> "icon");
			} else {
				if !(_item isEqualTo "") then {
					_icon = getText (missionConfigFile >> "CfgVirtualItems" >> (getText (_goalCfg >> "item")) >> "icon");
				};
			};

			if !(_icon isEqualTo "") then {
				private _iconCtrl = _goal controlsGroupCtrl 101;
				_iconCtrl ctrlSetText _icon;
			};

			private _nameCtrl = _goal controlsGroupCtrl 102;
			_nameCtrl ctrlSetText getText (_goalCfg >> "title");

			private _descCtrl = _goal controlsGroupCtrl 103;
			_descCtrl ctrlSetStructuredText parseText format[getText (_goalCfg >> "description")];
			_descCtrl ctrlEnable false;

			private _max = (_tiers select ((count _tiers) - 1));

			private _progressCtrl = _goal controlsGroupCtrl 104;
			_progressCtrl progressSetPosition (_progress / _max);
			(ctrlPosition _progressCtrl) params ["_xAxis", "_yAxis", "_w", "_h"];

			{
				private _line = _display ctrlCreate ["Life_RscText", -1, _goal];
				_line ctrlSetBackgroundColor ([[1, 1, 1, 1], [0.196, 0.659, 0.388, 1]] select (_progress >= _x));
				_line ctrlSetPosition [_xAxis + (_w * (_x / _max)), _yAxis, 0.15 * GUI_GRID_CENTER_W, _h];
				_line ctrlSetTooltip format["Tier %1", _forEachIndex + 1];
				_line ctrlCommit 0;
				_ctrls pushBack _line;
			} forEach _tiers;

			private _proTxtCtrl = _goal controlsGroupCtrl 105;
			_proTxtCtrl ctrlSetText format["%1/%2", [_progress] call ULP_fnc_numberText, [_max] call ULP_fnc_numberText];

			_goal ctrlCommit 0;

			_lastCtrlPos = ctrlPosition _goal;
			_ctrls pushBack _goal;
		};
	} forEach _rawGoals;

	_ctrls pushBack _goalHeader;
} forEach ["Daily", "Weekly"];

_display setVariable ["display_ctrls", _ctrls];