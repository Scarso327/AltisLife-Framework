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

private _paramKeys = getArray (_cfg >> "params");

if !((count _params) isEqualTo (count _paramKeys)) exitWith {
	[format ["Player Event Params: %1 (%2)", _params, _steamid]] call ULP_fnc_logIt;
};

private _hashMapParams = createHashMap;

{
	_hashMapParams set [_x, _params select _forEachIndex];
} forEach _paramKeys;

private _jsonContent = toJSON _hashMapParams;
private _season = missionNamespace getVariable ["ULP_SRV_Setting_Season", 1];

[
	format ["INSERT INTO `logs` (`event`, `pid`, `content`, `jsonContent`, `season`) VALUES('%1', '%2', '%3', '%4', '%5')",
		_event,
		_steamid,
		[_params] call DB_fnc_mresArray,
		_jsonContent,
		[_season, ""] call ULP_fnc_numberText
	], 1
] call DB_fnc_asyncCall;