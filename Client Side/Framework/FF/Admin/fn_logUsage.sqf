/*
	@File: fn_logUsage.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Logs the usage of an admin command and tells other admins (if needed) that we used it...
*/
#include "..\..\script_macros.hpp"
params [
	["_notify", true, [false]],
	["_message", "", [""]]
];

if (_message isEqualTo "") exitWith {};

// Logging will be done here...

// Notifing will be done here...
if (_notify) then { [_message, "(call life_adminlevel) > 0"] remoteExecCall ["FF_fnc_hint", RCLIENT] };