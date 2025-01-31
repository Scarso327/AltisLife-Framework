/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_setGroupPermissions";

_this params [
	["_group", grpNull, [grpNull]]
];

if (isNull _group) exitWith { false };

private _permissions = + ([_group] call ULP_fnc_groupPermissions);

private _deposit = _permissions getOrDefault ["deposit", getNumber (missionConfigFile >> "CfgGroups" >> "Permissions" >> "deposit")];
private _withdraw = _permissions getOrDefault ["withdraw", getNumber (missionConfigFile >> "CfgGroups" >> "Permissions" >> "withdraw")];
private _rank = _permissions getOrDefault ["rank", getNumber (missionConfigFile >> "CfgGroups" >> "Permissions" >> "rank")];
private _invite = _permissions getOrDefault ["invite", getNumber (missionConfigFile >> "CfgGroups" >> "Permissions" >> "invite")];
private _kick = _permissions getOrDefault ["kick", getNumber (missionConfigFile >> "CfgGroups" >> "Permissions" >> "kick")];

// Update Group Information...
[format["UPDATE `groups` SET `deposit` = '%2', `withdraw` = '%3', `rank` = '%4', `invite` = '%5', `kick` = '%6' WHERE `id` = '%1'", 
	[[_group] call ULP_fnc_groupId, ""] call ULP_fnc_numberText,
	[_deposit, ""] call ULP_fnc_numberText,
	[_withdraw, ""] call ULP_fnc_numberText,
	[_rank, ""] call ULP_fnc_numberText,
	[_invite, ""] call ULP_fnc_numberText,
	[_kick, ""] call ULP_fnc_numberText
], 1] call DB_fnc_asyncCall;

true