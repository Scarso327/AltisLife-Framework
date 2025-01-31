/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getGroupFunds";

_this params [
	["_groupId", -1, [0]]
];

if (_groupId isEqualTo -1) exitWith { 0 };

private _query = [format["SELECT `groups`.`bank` FROM `groups` WHERE `groups`.`id` = '%1' AND `groups`.`active`='1'",
	_groupId
], 2] call DB_fnc_asyncCall;

if !(_query isEqualType []) exitWith { 0 };

(_query param [0, 0, [0]])