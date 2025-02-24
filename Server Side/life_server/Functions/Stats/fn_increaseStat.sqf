/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_increaseStat";

_this params [
	["_event", "Misc", [""]],
	["_params", [], [[]]]
];

private _cfg = configFile >> "CfgPatches" >> "ULPServer" >> "EventLogs" >> _event >> "Stats"; 
if (!isClass _cfg) exitWith {};

private _amount = getNumber (_cfg >> "amount");
private _players = _params call compile getText (_cfg >> "players");

private _season = missionNamespace getVariable ["ULP_SRV_Setting_Season", 1];

// TODO 
// logPlayerEvent params need to use the new toJson methods
// That way I can just query log information instead of logging stats
// themselves

{
	private _stat = _x;

	{
		private _result = [format["SELECT `id`, `value` FROM `player_stats` WHERE `pid`='%1' AND `season`='%2' AND `event`='%3'", _x, _season, _stat], 2] call DB_fnc_asyncCall;

		if (_result isEqualType "" || { _result isEqualTo [] }) then {
			[format ["INSERT INTO `player_stats` (`pid`, `season`, `event`, `value`) VALUES ('%1', '%2', '%3', '%4')", 
				_steamId, 
				[_season, ""] call ULP_fnc_numberText,
				_stat,
				[_amount, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
		} else {
			_result params [ "_id", "_value" ];
			_value = _value + _amount;

			[format ["UPDATE `player_stats` SET `value` = '%1' WHERE `id` = '%2'", _value, [_id, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
		};
		nil
	} count _y;
} forEach _players;