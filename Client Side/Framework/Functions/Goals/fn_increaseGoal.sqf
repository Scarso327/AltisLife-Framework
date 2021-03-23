/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_increaseGoal";

_this params [
	["_goal", [], [[]]],
	["_goalCfg", configNull, [configNull]]
];

private _tiers = getArray (_goalCfg >> "tiers");
private _max = (_tiers select ((count _tiers) - 1));
_progress = ((_progress + _amount) min _max);

private _newTier = _tiers findIf { _progress <= _x };
if (_newTier <= -1) then { _newTier = 0; };

_goal set [1, _progress];

private _completed = (_max isEqualTo _progress);
if (_completed) then { _newTier = _newTier + 1; };

if !(_tier isEqualTo _newTier) then {
	_goal set [2, _newTier];
	[_goalCfg, _newTier] call ULP_fnc_rewardTier;
};

_goal set [3, _completed];

_goal