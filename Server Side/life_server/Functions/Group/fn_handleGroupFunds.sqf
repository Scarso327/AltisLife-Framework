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

private _result = [_groupId, _amount, _add] call ULP_SRV_fnc_updateGroupFunds;

if (_add || { _unit isEqualType grpNull } || { !isPlayer _unit }) exitWith {};

if !(_result) exitWith {
	["GroupWithdraw", [format ["Your group doesn't have %1%2 to withdraw...", "£", [_amount] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

["GroupWithdraw", [
	format ["You've withdrawn %1%2 from your group funds...", "£", [_amount] call ULP_fnc_numberText], _amount, _funds
]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];