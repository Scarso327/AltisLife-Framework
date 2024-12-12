/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_handleVotes";

private _winner = ["SELECT `candidates`.`name`, `candidates`.`pid`, (SELECT SUM(`vote_count`.`amount`) FROM `votes` AS `vote_count` WHERE `vote_count`.`candidate` = `candidates`.`id`) AS `total_votes` FROM `candidates` INNER JOIN `votes` ON `candidates`.`id` = `votes`.`candidate` WHERE `candidates`.`active` = '1' AND `votes`.`active` = '1' ORDER BY `total_votes` DESC LIMIT 1;", 2] call DB_fnc_asyncCall;
if !(_winner isEqualType []) then { _winner = []; };

if !(_winner isEqualTo []) then {
	_winner params [ "_name", "_steamid", "_votes" ];

	// Logging...
	[format ["Election Winner: %1 (%2) with %3 votes", _name, _steamid, [_votes] call ULP_fnc_numberText]] call ULP_fnc_logIt;
	["SYSTEM", "Election", ["Winner", [_name, _steamid, [_votes, ""] call ULP_fnc_numberText]]] call ULP_SRV_fnc_logPlayerEvent;

	[format ["UPDATE `settings` SET `value` = '%1' WHERE `setting` = 'Governor'", [[_name, _steamid]] call DB_fnc_mresArray], 1] call DB_fnc_asyncCall;

	missionNamespace setVariable ["ULP_SRV_Setting_Governor", [_name, _steamid], true];
};

// Wipe...
["UPDATE `candidates` SET `active` = '0'", 1] call DB_fnc_asyncCall;
["UPDATE `votes` SET `active` = '0'", 1] call DB_fnc_asyncCall;