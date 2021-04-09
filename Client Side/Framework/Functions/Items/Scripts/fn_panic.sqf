/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_panic";

if ((["PanicButton"] call ULP_fnc_hasItem) < 1) exitWith {};

// Stop spam...
private _cd = player getVariable ["panic_cooldown", 0];
if (time < _cd) exitWith {
	hint format ["You used your panic button recently and can't use it for another %1 seconds...", [_cd - time] call ULP_fnc_numberText];
	false
};
player setVariable ["panic_cooldown", time + 60];

private _cfg = missionConfigFile >> "CfgMessages" >> "Panic";
private _targets = getText (_type >> "targets");

[_cfg, format ["%1 has pressed their panic button! They are in need of immediate help.", name player], _targets] call ULP_fnc_sendMessage;
hint "You have pressed your panic button, the police have been alerted!";

[player, "Backup", 100, 1] remoteExecCall ["ULP_fnc_say3D"];

true