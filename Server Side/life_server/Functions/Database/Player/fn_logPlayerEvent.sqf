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
	format ["INSERT INTO `logs` (`event`, `pid`, `content`) VALUES('%1', '%2', '%3')",
		_event,
		_steamid,
		// TODO: Use https://community.bistudio.com/wiki/toJSON to save this is a format I can query
		// Comment in fn_increaseStat so I can just query logs
		[_params] call DB_fnc_mresArray
	], 1
] call DB_fnc_asyncCall;

private _statParams = [_steamid];
_statParams append _params;

[_event, _statParams] call ULP_SRV_fnc_increaseStat;