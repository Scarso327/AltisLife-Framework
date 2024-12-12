/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setGroupOwner";

_this params [
	["_groupid", -1, [0]],
	["_owner", "", [""]],
	["_new", "", [""]]
];

if (_groupid < 0 || { _owner isEqualTo "" } || { _new isEqualTo "" }) exitWith { false };

// Update Group Information...
[format["UPDATE `groups` SET `owner` = '%1' WHERE `owner`='%2' AND `id` = '%3'", _new, _owner, [_groupid, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;

// Update Player Information...
[format["UPDATE `players` SET `group_level` = '5' WHERE `pid`='%1' AND `group_id` = '%2'", _owner, [_groupid, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
[format["UPDATE `players` SET `group_level` = '6' WHERE `pid`='%1' AND `group_id` = '%2'", _new, [_groupid, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;

true