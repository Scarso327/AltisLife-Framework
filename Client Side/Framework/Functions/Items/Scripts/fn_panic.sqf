/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_panic";

if ((["PanicButton"] call ULP_fnc_hasItem) < 1) exitWith {};

// Stop spam...
private _cd = player getVariable ["panic_cooldown", 0];
if (time < _cd) exitWith {
	[format ["You used your panic button recently and can't use it for another <t color='#B92DE0'>%1</t> seconds...", [_cd - time] call ULP_fnc_numberText]] call ULP_fnc_hint;
	false
};
player setVariable ["panic_cooldown", time + 60];

private _cfg = missionConfigFile >> "CfgMessages" >> "Panic";
private _targets = getText (_cfg >> "targets");

[_cfg, "A panic button has pressed! Immediate assistance is required.", _targets] call ULP_fnc_sendMessage;
["You have pressed your panic button, the police have been alerted!"] call ULP_fnc_hint;

[player, "panicButton", 100, 1] remoteExecCall ["ULP_fnc_say3D"];

true