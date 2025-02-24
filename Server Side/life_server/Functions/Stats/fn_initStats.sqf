/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initStats";

["Initialising Stats / Seasons..."] call ULP_fnc_logIt;

private _date = _this;

private _season = missionNamespace getVariable ["ULP_SRV_Setting_Season", 1];

// Start New Season
if (ULP_SRV_Setting_NextSeason isEqualTo _date) then {
	["Starting a new season!"] call ULP_fnc_logIt;
	_season = _season + 1;

	[format ["UPDATE settings SET value = '%1' WHERE setting = 'Season'", [_season, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
	// Honestly wtf was I doing with this query? It's disgusting but I know it works and lazy mood rn
	[str parseText format ["UPDATE settings SET value = DATE_FORMAT(ADDDATE(CURDATE(), INTERVAL %1 DAY), '&#37;Y-&#37;c-&#37;e') WHERE setting = 'NextSeason'", 14], 1] call DB_fnc_asyncCall;
};

missionNamespace setVariable ["ULP_SRV_Setting_Season", _season, true];