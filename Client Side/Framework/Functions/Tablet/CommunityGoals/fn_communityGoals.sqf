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
			["_communityGoals", createHashMap, [createHashMap]]
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
			_y params [ "_progress", "_myProgress" ];

			private _goalCfg = missionConfigFile >> "CfgGoals" >> "Community" >> _x;

			if (isClass _goalCfg) then {
				private _goal = _display ctrlCreate ["ULP_ctrlGoal", -1, _ctrlGroup];

				if !(_lastCtrlPos isEqualTo []) then {
					_goal ctrlSetPositionY (((_lastCtrlPos # 1) + ((1 * GUI_GRID_CENTER_H) / 2)) + (_lastCtrlPos # 3));
				};

				_lastCtrlPos = ctrlPosition _goal;
				_ctrls pushBack _goal;
			};
		} foreach _communityGoals;

		_display setVariable ["display_ctrls", _ctrls];
	}] call ULP_fnc_addEventHandler)];