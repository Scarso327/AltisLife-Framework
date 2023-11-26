/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
#include "..\..\..\UI\gridCommon.inc"
scopeName "fn_communityGoals";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

private _ctrls = _display getVariable ["display_ctrls", []];

if !(_ctrls isEqualTo []) then {
	{ ctrlDelete _x; } forEach _ctrls;
};

_display setVariable ["community_goals_received", (["CommunityGoalsReceived", {
		_this params [
			["_communityGoals", [], [[]]]
		];

		private _display = findDisplay 23000;
		private _ctrlGroup = _display displayCtrl 23090;

		// If our ctrlGroup is not shown we're no longer on this page and this event handler should not be here
		if (isNull _display || { !(ctrlShown _ctrlGroup) }) exitWith { [_event, _eventId] call ULP_fnc_removeEventHandler; };

		private _ctrls = _display getVariable ["display_ctrls", []];

		if !(_ctrls isEqualTo []) then {
			{ ctrlDelete _x; } forEach _ctrls;
		};

		_ctrls = [];

		private _lastCtrlPos = ctrlPosition controlNull;

		{
			_x params [ "_cfgName", "_progress", "_myProgress", "_daysLeft" ];

			private _goalCfg = missionConfigFile >> "CfgGoals" >> "Community" >> _cfgName;

			if (isClass _goalCfg && { [player, getArray (_goalCfg >> "factions")] call ULP_fnc_isFaction }) then {
				private _tiers = getArray (_goalCfg >> "tiers");
				private _goal = _display ctrlCreate ["ULP_ctrlCommunityGoal", -1, _ctrlGroup];

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
				_nameCtrl ctrlSetText format ["%1 (%2 Day(s) Left)", getText (_goalCfg >> "title"), _daysLeft];

				([_goalCfg, _progress, _myProgress] call ULP_fnc_getCommunityGoalPayout) params [ "_currentPayout", "_myPayout" ];

				private _descCtrl = _goal controlsGroupCtrl 103;
				_descCtrl ctrlSetStructuredText parseText format["Current Payout: <t color='#B92DE0'>%1%2</t><br/>Your Payout: <t color='#B92DE0'>%1%3</t>", 
					"£", [_currentPayout] call ULP_fnc_numberText, [_myPayout] call ULP_fnc_numberText];
				_descCtrl ctrlEnable false;

				private _progressCtrl = _goal controlsGroupCtrl 104;
				private _myProgressCtrl = _goal controlsGroupCtrl 106;

				private _max = (_tiers select ((count _tiers) - 1));

				_progressCtrl progressSetPosition (_progress / _max);
				_myProgressCtrl progressSetPosition (_myProgress / _max);

				(ctrlPosition _myProgressCtrl) params ["_xAxis", "_yAxis", "_w", "_h"];

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
				_proTxtCtrl ctrlSetTooltip format ["Your Contribution (%1%2)", (_myProgress / (_progress max 1)) * 100, "%"];
				
				_goal ctrlCommit 0;

				_lastCtrlPos = ctrlPosition _goal;
				_ctrls pushBack _goal;
			};
		} foreach _communityGoals;

		_display setVariable ["display_ctrls", _ctrls];
	}] call ULP_fnc_addEventHandler)];

[player] remoteExecCall ["ULP_SRV_fnc_getCommunityGoals", RSERV];