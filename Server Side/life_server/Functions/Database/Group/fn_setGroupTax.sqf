/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setGroupTax";

_this params [
	["_group", grpNull, [grpNull]],
	["_tax", 0, [0]]
];

if (isNull _group || { _tax < 0 }) exitWith { false };

_group setVariable ["group_tax", _tax / 100, true];

// Update Group Information...
[format["UPDATE `groups` SET `tax` = '%1' WHERE `id` = '%2'", 
	[_tax, ""] call ULP_fnc_numberText, 
	[[_group] call ULP_fnc_groupId, ""] call ULP_fnc_numberText
], 1] call DB_fnc_asyncCall;

true