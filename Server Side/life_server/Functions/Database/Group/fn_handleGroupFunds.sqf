/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_handleGroupFunds";

_this params [
	["_unit", objNull, [objNull, grpNull]],
	["_amount", 0, [0]],
	["_add", false, [true]]
];

private _group = _unit;
if (_group isEqualType objNull) then {
   _group = group _unit;
};

private _groupId = [_group] call ULP_fnc_groupId;

if (isNull _unit || { !([_group] call ULP_fnc_isGroup) } || { _amount < 0 }) exitWith {};

private _funds = + (_group getVariable ["group_funds", 0]);

if (_add) then {
	_funds = _funds + _amount;
} else {
	if (_funds < _amount) exitWith {
		if (!(_unit isEqualType grpNull) && { isPlayer _unit }) then {
			["GroupWithdraw", [format ["Your group doesn't have %1%2 to withdraw...", "£", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
		};
	};

	_funds = _funds - _amount;
	if (!(_unit isEqualType grpNull) && { isPlayer _unit }) then {
		["GroupWithdraw", [
			format ["You've withdrawn %1%2 from your group funds...", "£", [_amount] call ULP_fnc_numberText], _amount, _funds
		]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	};
};

if !((_group getVariable ["group_funds", 0]) isEqualTo _funds) then {
	if (_groupId > 0) then {
		[format[
			"UPDATE `groups` SET bank='%2' WHERE id='%1'", 
			[_groupId, ""] call ULP_fnc_numberText, [_funds, ""] call ULP_fnc_numberText
		], 1] call DB_fnc_asyncCall;

		if (!(_unit isEqualType grpNull) && { isPlayer _unit }) then {
			[getPlayerUID _unit, "Group", ["Funds", _groupid, [_funds, ""] call ULP_fnc_numberText]] call ULP_SRV_fnc_logPlayerEvent;
		};
	};
	
	if (_funds < 1) then { _funds = nil; }; // Wipe the vars if it's empty...

	_group setVariable ["group_viewablefunds", _funds, true];
	_group setVariable ["group_funds", _funds];

	["GroupMoneyChanged", [_amount, _funds]] remoteExecCall ["ULP_fnc_invokeEvent", (units _group)];
};