/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addGroupBuff";

_this params [
	["_group", grpNull, [grpNull]],
	["_buff", "", [""]],
	["_amount", 0.01, [0]]
];

private _cfg = missionConfigFile >> "CfgGroups" >> "Buffs" >> _buff;
if (isNull _group || { !([_group] call ULP_fnc_isGroup) } || { !(isClass _cfg) }) exitWith { false };

private _current = [_group] call ULP_fnc_groupBuff;
private _level = ((_current + _amount) min getNumber (_cfg >> "max"));

if !(_level isEqualTo _current) then {
	private _buffs = + (_group getVariable ["group_buffs", createHashMap]);
	_buffs set [_buff, _level];
	_group setVariable ["group_buffs", _buffs, true];

	[format[
		"UPDATE groups SET buffs='%2' WHERE id='%1'", 
		[[_group] call ULP_fnc_groupId, ""] call ULP_fnc_numberText, [_buffs] call DB_fnc_mresArray
	], 1] call DB_fnc_asyncCall;
};