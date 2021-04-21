/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setGroupId";

_this params [
	["_steamid", "", [""]],
	["_groupid", -1, [0]]
];

if (_steamid isEqualTo "") exitWith { false };

// If we're setting our id to less than 0 we're probably leaving...
if (_groupid < 0) then {
	[format["UPDATE candidates SET active='0' WHERE pid='%1';", _steamid], 1] call DB_fnc_asyncCall;
};

[format[
	"UPDATE players SET group_id = '%2', group_level = '0' WHERE pid='%1'", 
	_steamid, [_groupid, ""] call ULP_fnc_numberText
], 1] call DB_fnc_asyncCall;
true