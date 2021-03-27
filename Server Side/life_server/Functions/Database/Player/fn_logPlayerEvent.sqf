/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_logPlayerEvent";

_this params [
	["_steamid", "", [""]],
	["_event", "Misc", [""]],
	["_params", [], [[]]]
];

private _cfg = configFile >> "CfgPatches" >> "ULPServer" >> "EventLogs" >> _event;
if (isNull _cfg || { _steamid isEqualTo "" }) exitWith {
	[format ["Player Event Unknown: %1 (%2)", _event, _steamid]] call ULP_fnc_logIt;
};

if (isNumber (_cfg >> "params") && { !((count _params) isEqualTo getNumber (_cfg >> "params")) }) exitWith {
	[format ["Player Event Params: %1 (%2)", _params, _steamid]] call ULP_fnc_logIt;
};

[
	format ["INSERT INTO logs (event, pid, content) VALUES('%1', '%2', '%3')",
		_event,
		_steamid,
		[[_params] call DB_fnc_mresArray] call DB_fnc_mresJson
	], 1
] call DB_fnc_asyncCall;