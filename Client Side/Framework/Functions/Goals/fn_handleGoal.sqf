/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_handlelGoal";

if (canSuspend) exitWith {
    [ULP_fnc_handleGoal, _this] call ULP_fnc_directCall;
};

_this params [
	["_type", "GATHERING", [""]],
	["_params", [], [[]]],
	["_code", {}, [{}]]
];

private _allCompleted = true;

{
	private _goalType = _x;
	private _activeGoals = missionNamespace getVariable format["ULP_Goals_%1", _goalType];

	if (!(isNil "_activeGoals") && { _type in _activeGoals }) then {
		private _goals = (_activeGoals get _type);

		{
			_allCompleted = false;
			_goals set [_forEachIndex, ([_params, _x, _goalType] call _code)];
		} forEach (_goals select { !(_x select 3) });

		_activeGoals set [_type, _goals];
		missionNamespace setVariable [format["ULP_Goals_%1", _goalType], _activeGoals];
	};
} forEach ["Daily", "Weekly"];

if !(_allCompleted) then { [] call ULP_fnc_saveGoals; };

_allCompleted