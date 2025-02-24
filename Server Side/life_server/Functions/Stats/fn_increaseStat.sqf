/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_increaseStat";

_this params [
	["_steamId", "", [""]],
	["_event", "Misc", [""]]
];

// TODO Add ability to modify the increment amount

private _cfg = configFile >> "CfgPatches" >> "ULPServer" >> "EventLogs" >> _event;
if (isNull _cfg || { _steamId isEqualTo "" } || { !([getNumber (_cfg >> "isStat")] call ULP_fnc_bool) }) exitWith { false };

private _season = missionNamespace getVariable ["ULP_SRV_Setting_Season", 1];

private _result = [format["SELECT `id`, `value` FROM `player_stats` WHERE `pid`='%1' AND `season`='%2'", _steamId, _season], 2] call DB_fnc_asyncCall;

if (_result isEqualType "" || { _result isEqualTo [] }) exitWith {
	[format ["INSERT INTO `player_stats` (`pid`, `season`, `event`, `value`) VALUES ('%1', '%2', '%3', '%4')", 
		_steamId, 
		[_season, ""] call ULP_fnc_numberText,
		_event,
		[1, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
		
	true
};

_result params [ "_id", "_value" ];
_value = _value + 1;

[format ["UPDATE `player_stats` SET `value` = '%1' WHERE `id` = '%2'", _value, [_id, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
true