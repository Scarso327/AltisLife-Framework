/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_saveLegislation";

_this params [
	["_legislation", "", [""]],
	["_value", 0, [0, "", false, []]]
];

private _settings = + (missionNamespace getVariable ["ULP_SRV_Setting_GovernorSettings", createHashMap]);
_settings set [_legislation, _value];
missionNamespace setVariable ["ULP_SRV_Setting_GovernorSettings", _settings, true];

[format[
	"UPDATE settings SET value='%1' WHERE setting='GovernorSettings'", 
	[_settings] call DB_fnc_mresArray
], 1] call DB_fnc_asyncCall;

["LegislationChanged"] remoteExecCall ["ULP_fnc_invokeEvent", RCLIENT];