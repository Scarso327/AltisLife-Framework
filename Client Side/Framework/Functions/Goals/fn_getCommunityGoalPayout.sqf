/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getCommunityGoalPayout";

_this params [
	["_goalCfg", configNull, [configNull]],
	["_progress", 0, [0]],
	["_myProgress", 0, [0]]
];

if (isNull _goalCfg || { _progress isEqualTo 0 }) exitWith { [0, 0] };

private _tiers = getArray (_goalCfg >> "tiers");

private _lastIndex = (count _tiers) - 1; 
private _max = _tiers param [_lastIndex, 0, [0]]; 
 
private _maxPayout = getNumber (_goalCfg >> "maxPayout");
private _basePay = getNumber (_goalCfg >> "basePayout");
 
_tiers sort false;

private _tier = (_tiers findIf { _progress >= _x });
if (_tier isEqualTo -1) exitWith { [0, 0] };

private _tierTarget = _tiers param [_tier, 0, [0]];
private _payOut = (_maxPayout * (_tierTarget / _max));

private _myContribution = _myProgress / (_progress max 1);
private _myPayout = floor (_payOut * _myContribution);

[_payOut, _myPayout]