/*
	@File: fn_logUsage.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Logs the usage of an staff power and tells other staff.
*/
#include "..\..\script_macros.hpp"
params [
	["_notify", true, [false]],
	["_message", "", [""]]
];

if (_message isEqualTo "") exitWith {};

if (_notify) then { [_message, "(call life_adminlevel) > 0"] remoteExecCall ["FF_fnc_hint", RCLIENT] };