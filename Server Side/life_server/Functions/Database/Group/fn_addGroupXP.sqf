/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addGroupXP";

_this params [
	["_group", grpNull, [grpNull]],
	["_xp", "", [""]]
];

private _cfg = missionConfigFile >> "CfgGroups" >> "Leveling" >> "XP" >> _xp;
if (isNull _group || { !([_group] call ULP_fnc_isGroup) } || { !(isClass _cfg) }) exitWith { false };

private _level = [_group] call ULP_fnc_groupLevel;
private _required = [(_level + 1), missionConfigFile >> "CfgGroups" >> "Leveling"] call ULP_fnc_getRequiredXP;
private _max = [missionConfigFile >> "CfgGroups" >> "Leveling"] call ULP_fnc_getMaxLevel;

private _xp = round(([_group] call ULP_fnc_groupXP) + getNumber (_cfg >> "amount"));

private _previousLevel = [_group] call ULP_fnc_groupLevel;

for "_i" from 0 to 1 step 0 do {
	scopeName "fn_addXP_rankLoop";

	if (_xp < _required) exitWith {};

	if (_xp >= _required) then {
		if (_level isEqualTo _max) then {
			_xp = _required;
			breakOut "fn_addXP_rankLoop";
		} else {
			_xp = _xp - _required;
			_level = _level + 1;
			_required = [(_level max 1), missionConfigFile >> "CfgGroups" >> "Leveling"] call ULP_fnc_getRequiredXP;
		};
	};
};

_group setVariable ["group_progression", [_level, _xp], true];

[format[
	"UPDATE `groups` SET `level`='%2', `xp`='%3' WHERE `id`='%1'", 
	[[_group] call ULP_fnc_groupId, ""] call ULP_fnc_numberText, [_level, ""] call ULP_fnc_numberText, [_xp, ""] call ULP_fnc_numberText
], 1] call DB_fnc_asyncCall;

true