/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_knockOut";

_this params [
	["_target", cursorObject, [objNull]]
];

// Checks...
if (isNull _target || { !(isPlayer _target) } || 
	{ _target isEqualTo player } || { (_target distance player) >= 3 } || 
	{ isDowned(_target) } || { isDowned(player) } ||
	{ time <= missionNamespace getVariable["ULP_KnockOut_Cooldown", 0] } ||
	{ [player] call ULP_fnc_isKnocked } || { [_target] call ULP_fnc_isKnocked }
) exitWith { false };

if ([player, "AwopPercMstpSgthWrflDnon_End2"] call ULP_fnc_switchMove) exitWith {
	missionNamespace setVariable["ULP_KnockOut_Cooldown", time + 5];

	[0.08, _target, { [player] remoteExecCall ["ULP_fnc_onKnocked", _this] }] call ULP_fnc_waitExecute;
	true
};

false