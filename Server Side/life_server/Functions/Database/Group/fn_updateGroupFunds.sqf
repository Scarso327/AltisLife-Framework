/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_updateGroupFunds";

_this params [
	["_groupId", -1, [0]],
	["_amount", 0, [0]],
	["_add", false, [true]]
];

if (_groupId < 0 || {  _amount < 0 }) exitWith { false };

private _group = [_groupId] call ULP_fnc_getGroupById;

private _funds = if (isNull _group) then {
	([_groupId] call ULP_SRV_fnc_getGroupFunds)
} else {
	(+ (_group getVariable ["group_funds", 0]))
};

private _originalFunds = + _funds;

if (_add) then {
	_funds = _funds + _amount;
} else {
	if (_funds < _amount) exitWith {
		false breakOut "fn_updateGroupFunds";
	};

	_funds = _funds - _amount;
};

if !(_funds isEqualTo _originalFunds) then {
	[format[
		"UPDATE `groups` SET bank='%2' WHERE id='%1'", 
		[_groupId, ""] call ULP_fnc_numberText, [_funds, ""] call ULP_fnc_numberText
	], 1] call DB_fnc_asyncCall;

	if (!(_unit isEqualType grpNull) && { isPlayer _unit }) then {
		[getPlayerUID _unit, "Group", ["Funds", _groupId, [_funds, ""] call ULP_fnc_numberText]] call ULP_SRV_fnc_logPlayerEvent;
	};

	if !(isNull _group) then {
		if (_funds < 1) then { _funds = nil; }; // Wipe the vars if it's empty...

		_group setVariable ["group_viewablefunds", _funds, true];
		_group setVariable ["group_funds", _funds];

		["GroupMoneyChanged", [_amount, _funds]] remoteExecCall ["ULP_fnc_invokeEvent", (units _group)];
	};
};

true