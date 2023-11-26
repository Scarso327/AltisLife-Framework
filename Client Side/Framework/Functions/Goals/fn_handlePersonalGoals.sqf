/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_handlePersonalGoals";

if (canSuspend) exitWith {
    [ULP_fnc_handlePersonalGoals, _this] call ULP_fnc_directCall;
};

_this params [
	["_eventType", "", [""]],
	["_params", [], [[]]]
];

if (_eventType isEqualTo "" || { _params isEqualTo [] }) exitWith { false };

private _allCompleted = true;

{
	private _goalType = _x;
	private _activeGoals = missionNamespace getVariable format["ULP_Goals_%1", _goalType];

	if (!(isNil "_activeGoals") && { _eventType in _activeGoals }) then {
		private _goals = (_activeGoals get _eventType);

		{
			_x params [ "_cfgName", "_progress", "_tier", "_completed" ];

			if !(_completed) then {
				private _goalCfg = missionConfigFile >> "CfgGoals" >> "Personal" >> _goalType >> _cfgName;

				// The "getQuantity" text in the config should return a quanity value
				// This allows us to hardcode "1" for things like arresting people where the params don't provide amounts
				private _amount = [getText (_goalCfg >> "item"), _params] call compile getText (_goalCfg >> "Event" >> "getQuantity");
				if (_amount <= 0) exitWith { _allCompleted = false; };

				private _tiers = getArray (_goalCfg >> "tiers");
				private _totalTiers = count _tiers;

				private _max = (_tiers select (_totalTiers - 1));

				_progress = ((_progress + _amount) min _max);

				// Increase progress artifically by 1 here to find current tier
				// Example:
				// Tiers = (100, 300, 500) and Progress = 100, 100 is equal to index 0 so it won't increase the tier
				// 101 would cause the findIf to return 1 and in turn our next tier
				private _newTier = ((_tiers findIf { (_progress + 1) <= _x }) max 0) min _totalTiers;

				_x set [1, _progress];

				_completed = (_max isEqualTo _progress);

				if (_completed) then {
					_newTier = _newTier + 1; // Increment by 1 to ensure it gives rewards for final tier
				} else {
					_allCompleted = false;
				};

				if !(_tier isEqualTo _newTier) then {
					_x set [2, _newTier];
					[_goalCfg, _newTier] call ULP_fnc_rewardPersonalGoal;
				};

				_x set [3, _completed];

				_goals set [_forEachIndex, _x];
			};
		} forEach _goals;

		_activeGoals set [_eventType, _goals];
		missionNamespace setVariable [format["ULP_Goals_%1", _goalType], _activeGoals];
	};
} forEach ["Daily", "Weekly"];

[] call ULP_fnc_savePersonalGoals;

_allCompleted